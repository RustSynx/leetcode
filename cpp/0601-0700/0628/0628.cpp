//
// Created by Milo on 7/26/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

class Solution {
public:
  int maximumProduct(vector<int>& nums) {
    int n = nums.size();
    ranges::sort(nums);
    int max1 = nums[0] * nums[1] * nums[n - 1];
    int max2 = nums[n - 1] * nums[n - 2] * nums[n - 3];
    return max(max1, max2);
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> nums = {1, 2, 3};
  int result = sol.maximumProduct(nums);
  int result_expected = 6;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums = {1, 2, 3, 4};
  result = sol.maximumProduct(nums);
  result_expected = 24;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  nums = {-1, -2, -3};
  result = sol.maximumProduct(nums);
  result_expected = -6;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}