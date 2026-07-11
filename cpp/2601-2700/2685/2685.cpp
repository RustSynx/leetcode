//
// Created by Milo on 7/11/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

struct UnionFind {
  vector<int> parent;
  vector<int> points;
  vector<int> lines;

  UnionFind(int node_size) {
    parent.resize(node_size);
    points.resize(node_size, 1);
    lines.resize(node_size, 0);

    for (int i = 0; i < node_size; i++) {
      parent[i] = i;
    }
  }
  int find(int i) {
    if (parent[i] != i) {
      parent[i] = find(parent[i]);
    }
    return parent[i];
  }
};

class Solution {
 public:
  int countCompleteComponents(int n, vector<vector<int>>& edges) {
    UnionFind uf(n);
    for (const auto& e : edges) {
      int e1 = uf.find(e[0]);
      int e2 = uf.find(e[1]);

      if (e1 != e2) {
        uf.parent[e2] = e1;
        uf.points[e1] += uf.points[e2];
        uf.lines[e1] += uf.lines[e2] + 1;
      } else {
        uf.lines[e1]++;
      }
    }
    int result = 0;
    for (int i = 0; i < n; i++) {
      if (uf.parent[i] == i) {
        int p = uf.points[i];
        int l = uf.lines[i];
        if (p * (p - 1) / 2 == l) {
          result++;
        }
      }
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {3, 4}};
  int result = sol.countCompleteComponents(6, edges);
  int result_expected = 3;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  edges = {{0, 1}, {0, 2}, {1, 2}, {3, 4}, {3, 5}};
  result = sol.countCompleteComponents(6, edges);
  result_expected = 1;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}