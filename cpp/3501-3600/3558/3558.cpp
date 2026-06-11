//
// Created by Milo on 6/11/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
 public:
  int assignEdgeWeights(vector<vector<int>>& edges) {
    int n = static_cast<int>(edges.size());
    long long mod = 1e9 + 7;
    unordered_map<int, vector<int>> edge_map;
    for (int i = 0; i < n; i++) {
      edge_map[edges[i][0]].push_back(edges[i][1]);
      edge_map[edges[i][1]].push_back(edges[i][0]);
    }
    queue<tuple<int, int>> bfs;
    vector<bool> visited(n + 2, false);
    for (int num : edge_map[1]) {
      visited[num] = true;
      bfs.push({num, 1});
    }
    int depth = 1;
    int result = 1;
    visited[1] = true;
    while (!bfs.empty()) {
      auto [node, curr_depth] = bfs.front();
      bfs.pop();
      for (int num : edge_map[node]) {
        if (!visited[num]) {
          visited[num] = true;
          bfs.push({num, curr_depth + 1});
        }
      }
      if (depth < curr_depth) {
        result = (result * 2) % mod;
      }
      depth = max(depth, curr_depth);
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<vector<int>> edges = {{1, 2}};
  int result = sol.assignEdgeWeights(edges);
  int result_expected = 1;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  edges = {{1, 2}, {1, 3}, {3, 4}, {3, 5}};
  result = sol.assignEdgeWeights(edges);
  result_expected = 2;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}