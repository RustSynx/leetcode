//
// Created by Milo on 5/16/26.
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
      int mid = start + (end - start) / 2;
      if (nums[mid] > nums[end]) {
        start = mid + 1;
      } else if (nums[mid] == nums[end]) {
        end -= 1;
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
  vector<int> nums = {1, 3, 5};
  int result = sol.findMin(nums);
  int result_expected = 1;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums = {2, 2, 2, 0, 1};
  result = sol.findMin(nums);
  result_expected = 0;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}