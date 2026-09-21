//
// Created by Milo on 9/21/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<long long> resultArray(vector<int>& nums, int k) {
    vector<long long> result(k);
    vector<long long> dp(k);
    for (int num : nums) {
      vector<long long> next_dp(k);
      int curr_mod = num % k;
      next_dp[curr_mod]++;
      for (int i = 0; i < k; i++) {
        int next_mod = i * curr_mod % k;
        next_dp[next_mod] += dp[i];
      }
      for (int i = 0; i < k; i++) {
        result[i] += next_dp[i];
      }
      dp = move(next_dp);
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> nums = {1, 2, 3, 4, 5};
  vector<long long> result = sol.resultArray(nums, 3);
  vector<long long> result_expected = {9, 2, 4};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums = {1, 2, 4, 8, 16, 32};
  result = sol.resultArray(nums, 4);
  result_expected = {18, 1, 2, 0};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  nums = {1, 1, 2, 1, 1};
  result = sol.resultArray(nums, 2);
  result_expected = {9, 6};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}