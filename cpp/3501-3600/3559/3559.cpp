//
// Created by Milo on 6/12/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> assignEdgeWeights(vector<vector<int>>& edges,
                                vector<vector<int>>& queries) {
    int n = static_cast<int>(edges.size());
    int mod = 1e9 + 7;
    vector<int> pow_vec(n + 2, 1);
    for (int i = 1; i <= n; i++) {
      pow_vec[i] = (pow_vec[i - 1] * 2) % mod;
    }
    vector<vector<int>> edge_map(n + 2);
    for (int i = 0; i < n; i++) {
      edge_map[edges[i][0]].push_back(edges[i][1]);
      edge_map[edges[i][1]].push_back(edges[i][0]);
    }
    int logN = log2(n) + 1;
    vector<vector<int>> parent(n + 2, vector<int>(logN, -1));
    vector<int> depth_vec(n + 2);
    vector<bool> visited(n + 2);
    queue<tuple<int, int>> nodes;
    nodes.push({1, 0});
    visited[1] = true;
    while (!nodes.empty()) {
      auto [node, depth] = nodes.front();
      nodes.pop();
      for (int next : edge_map[node]) {
        if (!visited[next]) {
          parent[next][0] = node;
          for (int i = 1; i < logN; i++) {
            if (parent[next][i - 1] != -1) {
              parent[next][i] = parent[parent[next][i - 1]][i - 1];
            } else {
              parent[next][i] = -1;
            }
          }
          visited[next] = true;
          depth_vec[next] = depth + 1;
          nodes.push({next, depth + 1});
        }
      }
    }
    vector<int> result;
    result.reserve(queries.size());
    for (vector<int> query : queries) {
      if (query[0] == query[1]) {
        result.push_back(0);
        continue;
      }
      int root1 = query[0];
      int root2 = query[1];
      if (depth_vec[root1] < depth_vec[root2]) swap(root1, root2);
      int diff = depth_vec[root1] - depth_vec[root2];
      for (int i = 0; i < logN; i++) {
        if ((diff >> i) & 1) {
          root1 = parent[root1][i];
        }
      }

      if (root1 != root2) {
        for (int i = logN - 1; i >= 0; i--) {
          if (parent[root1][i] != parent[root2][i]) {
            root1 = parent[root1][i];
            root2 = parent[root2][i];
          }
        }
        root1 = parent[root1][0];
      }

      int dist =
          depth_vec[query[0]] + depth_vec[query[1]] - 2 * depth_vec[root1];
      result.push_back(pow_vec[dist - 1]);
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<vector<int>> edges = {{1, 2}};
  vector<vector<int>> queries = {{1, 1}, {1, 2}};
  vector<int> result = sol.assignEdgeWeights(edges, queries);
  vector<int> result_expected = {0, 1};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  edges = {{1, 2}, {1, 3}, {3, 4}, {3, 5}};
  queries = {{1, 4}, {3, 4}, {2, 5}};
  result = sol.assignEdgeWeights(edges, queries);
  result_expected = {2, 1, 4};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}