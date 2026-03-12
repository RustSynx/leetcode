//
// Created by Milo on 3/12/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

struct UnionFind {
  vector<int> parent;
  UnionFind(int node_count) {
    parent.resize(node_count);
    for (int i = 0; i < node_count; i++) {
      parent[i] = i;
    }
  }
  int find(int x) {
    if (parent[x] != x) {
      parent[x] = find(parent[x]);
    }
    return parent[x];
  }
};

class Solution {
 public:
  int maxStability(int n, vector<vector<int>>& edges, int k) {
    UnionFind union_find(n);
    sort(edges.begin(), edges.end(),
         [](const vector<int>& a, const vector<int>& b) {
           if (a[3] != b[3]) return a[3] > b[3];
           return a[2] > b[2];
         });
    vector<int> essential_weight;
    essential_weight.reserve(edges.size());
    vector<int> upgrade_weight;
    upgrade_weight.reserve(edges.size());
    for (int i = 0; i < edges.size(); i++) {
      int root_one = union_find.find(edges[i][0]);
      int root_two = union_find.find(edges[i][1]);
      if (edges[i][3] == 1 && root_one == root_two) {
        return -1;
      }
      if (root_one != root_two) {
        union_find.parent[root_two] = root_one;
        if (edges[i][3] == 1) essential_weight.push_back(edges[i][2]);
        if (edges[i][3] == 0) upgrade_weight.push_back(edges[i][2]);
      }
    }
    if (essential_weight.size() + upgrade_weight.size() != n - 1) {
      return -1;
    }
    sort(upgrade_weight.begin(), upgrade_weight.end());
    for (int i = 0; i < min((int)upgrade_weight.size(), k); i++) {
      upgrade_weight[i] *= 2;
    }
    int result = INT_MAX;
    for (int w : essential_weight) result = min(result, w);
    for (int w : upgrade_weight) result = min(result, w);
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<vector<int>> input = {{0, 1, 2, 1}, {1, 2, 3, 0}};
  int result = sol.maxStability(3, input, 1);
  int result_expected = 2;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  input = {{0, 1, 4, 0}, {1, 2, 3, 0}, {0, 2, 1, 0}};
  result = sol.maxStability(3, input, 2);
  result_expected = 6;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  input = {{0, 1, 1, 1}, {1, 2, 1, 1}, {2, 0, 1, 1}};
  result = sol.maxStability(3, input, 0);
  result_expected = -1;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}