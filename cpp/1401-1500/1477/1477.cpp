//
// Created by Milo on 9/17/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int minSumOfLengths(vector<int>& arr, int target) {
    int n = arr.size();
    int min_len = INT_MAX;
    vector<int> dp(n, INT_MAX);
    int start = 0;
    int curr_sum = 0;
    int best_len = INT_MAX;
    for (int end = 0; end < n; end++) {
      curr_sum += arr[end];
      while (curr_sum > target && start <= end) {
        curr_sum -= arr[start];
        start++;
      }
      if (curr_sum == target) {
        int curr_len = end - start + 1;
        if (start > 0 && dp[start - 1] != INT_MAX) {
          min_len = min(min_len, dp[start - 1] + curr_len);
        }
        best_len = min(best_len, curr_len);
      }
      dp[end] = best_len;
    }
    return min_len == INT_MAX ? -1 : min_len;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> nums = {3, 2, 2, 4, 3};
  int result = sol.minSumOfLengths(nums, 3);
  int result_expected = 2;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums = {7, 3, 4, 7};
  result = sol.minSumOfLengths(nums, 7);
  result_expected = 2;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  nums = {4, 3, 2, 6, 2, 3, 4};
  result = sol.minSumOfLengths(nums, 6);
  result_expected = -1;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}