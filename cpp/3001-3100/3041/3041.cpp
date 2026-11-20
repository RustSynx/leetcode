//
// Created by Milo on 11/20/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxSelectedElements(vector<int>& nums) {
    int n = nums.size();
    ranges::sort(nums);
    vector<int> dp(nums[n - 1] + 2);
    int result = 0;
    for (int num : nums) {
      dp[num + 1] = dp[num] + 1;
      dp[num] = dp[num - 1] + 1;
      result = max(result, max(dp[num], dp[num + 1]));
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> nums = {2, 1, 5, 1, 1};
  int result = sol.maxSelectedElements(nums);
  int result_expected = 3;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums = {1, 4, 7, 10};
  result = sol.maxSelectedElements(nums);
  result_expected = 1;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}