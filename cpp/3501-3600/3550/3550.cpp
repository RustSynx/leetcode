//
// Created by Milo on 9/24/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int smallestIndex(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      int sum = 0;
      int copy_num = nums[i];
      while (copy_num > 0) {
        sum += copy_num % 10;
        copy_num /= 10;
      }
      if (i == sum) return i;
    }
    return -1;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> nums = {1, 3, 2};
  int result = sol.smallestIndex(nums);
  int result_expected = 2;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums = {1, 10, 11};
  result = sol.smallestIndex(nums);
  result_expected = 1;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  nums = {1, 2, 3};
  result = sol.smallestIndex(nums);
  result_expected = -1;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}