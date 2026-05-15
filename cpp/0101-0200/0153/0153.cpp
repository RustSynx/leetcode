//
// Created by Milo on 5/15/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int findMin(vector<int>& nums) {
    int n = static_cast<int>(nums.size());
    int start = 0;
    int end = n - 1;
    while (start < end) {
      int mid = (start + end) / 2;
      if (nums[mid] > nums[end]) {
        start = mid + 1;
      } else {
        end = mid;
      }
    }
    return nums[start];
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> nums = {3, 4, 5, 1, 2};
  int result = sol.findMin(nums);
  int result_expected = 1;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums = {4, 5, 6, 7, 0, 1, 2};
  result = sol.findMin(nums);
  result_expected = 0;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  nums = {11, 13, 15, 17};
  result = sol.findMin(nums);
  result_expected = 11;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}