//
// Created by Milo on 5/17/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  bool canReach(vector<int>& arr, int start) {
    vector<bool> visited(arr.size(), false);
    return findZero(arr, start, visited);
  }
  bool findZero(vector<int>& arr, int curr_idx, vector<bool>& visited) {
    if (curr_idx < 0 || curr_idx >= arr.size()) return false;
    if (arr[curr_idx] == 0) return true;
    if (visited[curr_idx]) return false;
    visited[curr_idx] = true;
    return findZero(arr, curr_idx - arr[curr_idx], visited) ||
           findZero(arr, curr_idx + arr[curr_idx], visited);
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> arr = {4, 2, 3, 0, 3, 1, 2};
  bool result = sol.canReach(arr, 5);
  bool result_expected = true;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  arr = {4, 2, 3, 0, 3, 1, 2};
  result = sol.canReach(arr, 0);
  result_expected = true;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  arr = {3, 0, 2, 1, 2};
  result = sol.canReach(arr, 2);
  result_expected = false;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}