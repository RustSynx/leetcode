//
// Created by Milo on 8/5/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
    unordered_map<int, vector<int>> nodes;
    for (vector<int>& v : invocations) {
      int ai = v[0];
      int bi = v[1];
      nodes[ai].push_back(bi);
    }
    queue<int> bug_que;
    unordered_set<int> bug_set;
    bug_que.push(k);
    bug_set.insert(k);
    while (!bug_que.empty()) {
      int curr = bug_que.front();
      bug_que.pop();
      for (int num : nodes[curr]) {
        if (!bug_set.contains(num)) {
          bug_set.insert(num);
          bug_que.push(num);
        }
      }
    }
    for (vector<int>& v : invocations) {
      int ai = v[0];
      int bi = v[1];
      if (!bug_set.contains(ai) && bug_set.contains(bi)) {
        vector<int> all(n);
        for (int i = 0; i < n; ++i) all[i] = i;
        return all;
      }
    }
    vector<int> result;
    result.reserve(n);
    for (int i = 0; i < n; ++i) {
      if (!bug_set.contains(i)) {
        result.push_back(i);
      }
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<vector<int>> invocations = {{1, 2}, {0, 1}, {3, 2}};
  vector<int> result = sol.remainingMethods(4, 1, invocations);
  vector<int> result_expected = {0, 1, 2, 3};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  invocations = {{1, 2}, {0, 2}, {0, 1}, {3, 4}};
  result = sol.remainingMethods(5, 0, invocations);
  result_expected = {3, 4};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  invocations = {{1, 2}, {0, 1}, {2, 0}};
  result = sol.remainingMethods(3, 2, invocations);
  result_expected = {};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}