//
// Created by Milo on 11/19/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int minimizeSum(vector<int>& nums) {
    int n = nums.size();
    ranges::sort(nums);
    return min(
        {nums[n - 1] - nums[2], nums[n - 2] - nums[1], nums[n - 3] - nums[0]});
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> nums = {1, 4, 7, 8, 5};
  int result = sol.minimizeSum(nums);
  int result_expected = 3;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums = {1, 4, 3};
  result = sol.minimizeSum(nums);
  result_expected = 0;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}