//
// Created by Milo on 3/17/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
#include <unordered_map>

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
  int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
    UnionFind union_find(static_cast<int>(source.size()));
    for (vector<int> v : allowedSwaps) {
      int root_a = union_find.find(v[0]);
      int root_b = union_find.find(v[1]);
      if (root_a != root_b) {
        union_find.parent[root_b] = root_a;
      }
    }
    int n = static_cast<int>(source.size());
    unordered_map<int, unordered_map<int, int>> groups;
    for (int i = 0; i < n; i++) {
      int root = union_find.find(i);
      groups[root][source[i]]++;
    }
    int result = 0;
    for (int i = 0; i < n; i++) {
      int root = union_find.find(i);
      if (groups[root][target[i]] > 0) {
        groups[root][target[i]]--;
      } else {
        result++;
      }
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> source = {1, 2, 3, 4};
  vector<int> target = {2, 1, 4, 5};
  vector<vector<int>> allowedSwaps = {{0, 1}, {2, 3}};
  int result = sol.minimumHammingDistance(source, target, allowedSwaps);
  int result_expected = 1;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  source = {1, 2, 3, 4};
  target = {1, 3, 2, 4};
  allowedSwaps = {};
  result = sol.minimumHammingDistance(source, target, allowedSwaps);
  result_expected = 2;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  source = {5, 1, 2, 4, 3};
  target = {1, 5, 4, 2, 3};
  allowedSwaps = {{0, 4}, {4, 2}, {1, 3}, {1,4}};
  result = sol.minimumHammingDistance(source, target, allowedSwaps);
  result_expected = 0;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}