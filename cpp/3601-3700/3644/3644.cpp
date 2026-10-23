//
// Created by Milo on 10/23/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int sortPermutation(vector<int>& nums) {
    int result = ~0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] != i) {
        result &= nums[i];
      }
    }
    if (result == ~0) return 0;
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> nums = {0, 3, 2, 1};
  int result = sol.sortPermutation(nums);
  int result_expected = 1;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums = {0, 1, 3, 2};
  result = sol.sortPermutation(nums);
  result_expected = 2;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  nums = {3, 2, 1, 0};
  result = sol.sortPermutation(nums);
  result_expected = 0;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}