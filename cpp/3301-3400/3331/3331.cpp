//
// Created by Milo on 11/21/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> findSubtreeSizes(vector<int>& parent, string s) {
    int n = parent.size();
    vector<int> last_seen(26, -1);
    vector<vector<int>> parent_node(n);
    for (int i = 1; i < n; i++) {
      parent_node[parent[i]].push_back(i);
    }
    vector<int> result(n, 1);
    auto dfs = [&](auto& self, int node) -> void {
      int idx = s[node] - 'a';
      int target = last_seen[idx] != -1 ? last_seen[idx] : parent[node];
      int prev = last_seen[idx];
      last_seen[idx] = node;
      for (int child : parent_node[node]) {
        self(self, child);
      }
      last_seen[idx] = prev;
      if (target != -1) {
        result[target] += result[node];
      }
    };
    dfs(dfs, 0);
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> parent = {-1, 0, 0, 1, 1, 1};
  vector<int> result = sol.findSubtreeSizes(parent, "abaabc");
  vector<int> result_expected = {6, 3, 1, 1, 1, 1};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  parent = {-1, 0, 4, 0, 1};
  result = sol.findSubtreeSizes(parent, "abbba");
  result_expected = {5, 2, 1, 1, 1};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}