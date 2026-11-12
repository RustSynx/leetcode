//
// Created by Milo on 11/12/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int longestMonotonicSubarray(vector<int>& nums) {
    int n = nums.size();
    int result = 1;
    int inc_start = 0;
    int dec_start = 0;
    for (int i = 0; i < n - 1; i++) {
      if (nums[i] >= nums[i + 1]) {
        inc_start = i + 1;
      }
      if (nums[i] <= nums[i + 1]) {
        dec_start = i + 1;
      }
      result = max(result, i + 1 - inc_start + 1);
      result = max(result, i + 1 - dec_start + 1);
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> nums = {1, 4, 3, 3, 2};
  int result = sol.longestMonotonicSubarray(nums);
  int result_expected = 2;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums = {3, 3, 3, 3};
  result = sol.longestMonotonicSubarray(nums);
  result_expected = 1;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  nums = {3, 2, 1};
  result = sol.longestMonotonicSubarray(nums);
  result_expected = 3;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}