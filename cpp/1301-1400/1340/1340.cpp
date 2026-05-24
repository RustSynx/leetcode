//
// Created by Milo on 5/24/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxJumps(vector<int>& arr, int d) {
    int n = static_cast<int>(arr.size());
    vector<pair<int, int>> idx_vec(n);
    for (int i = 0; i < n; i++) {
      idx_vec[i] = make_pair(arr[i], i);
    }
    ranges::sort(idx_vec, [](const pair<int,int>& a, const pair<int,int>& b) {
      return a.first < b.first;
    });
    vector<int> memo(n, 1);
    for (auto [num, idx] : idx_vec) {
      for (int i = idx + 1; i <= idx + d && i < n; i++) {
        if (arr[i] >= arr[idx]) {
          break;
        }
        memo[idx] = max(memo[idx], memo[i] + 1);
      }
      for (int i = idx - 1; i >= idx - d && i >= 0; i--) {
        if (arr[i] >= arr[idx]) {
          break;
        }
        memo[idx] = max(memo[idx], memo[i] + 1);
      }
    }
    return *max_element(memo.begin(), memo.end());
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> arr = {6, 4, 14, 6, 8, 13, 9, 7, 10, 6, 12};
  int result = sol.maxJumps(arr, 2);
  int result_expected = 4;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  arr = {3, 3, 3, 3, 3};
  result = sol.maxJumps(arr, 3);
  result_expected = 1;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  arr = {7, 6, 5, 4, 3, 2, 1};
  result = sol.maxJumps(arr, 1);
  result_expected = 7;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}