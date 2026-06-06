//
// Created by Milo on 6/6/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
      int n = static_cast<int>(nums.size());
      int left_sum = 0;
      int right_sum = 0;

      for (int num : nums) {
        right_sum += num;
      }

      vector<int> result(n, 0);
      for (int i = 0; i < n; i++) {
        right_sum -= nums[i];
        result[i] = abs(left_sum - right_sum);
        left_sum += nums[i];
      }

      return result;
    }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> nums = {10, 4, 8, 3};
  vector<int> result = sol.leftRightDifference(nums);
  vector<int> result_expected = {15, 1, 11, 22};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums = {1};
  result = sol.leftRightDifference(nums);
  result_expected = {0};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}