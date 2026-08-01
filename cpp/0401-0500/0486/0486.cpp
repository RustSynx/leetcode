//
// Created by Milo on 8/1/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  bool predictTheWinner(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
    return calcDiff(nums, 0, n - 1, dp) >= 0;
  }
  int calcDiff(vector<int>& nums, int start, int end, vector<vector<int>>& dp) {
    if (start == end) return nums[start];
    if (dp[start][end] != INT_MAX) return dp[start][end];

    int start_pick = nums[start] - calcDiff(nums, start + 1, end, dp);
    int end_pick = nums[end] - calcDiff(nums, start, end - 1, dp);
    return dp[start][end] = max(start_pick, end_pick);
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> nums = {1, 5, 2};
  bool result = sol.predictTheWinner(nums);
  bool result_expected = false;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums = {1, 5, 233, 7};
  result = sol.predictTheWinner(nums);
  result_expected = true;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}