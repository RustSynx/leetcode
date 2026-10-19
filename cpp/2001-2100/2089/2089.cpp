//
// Created by Milo on 10/19/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> targetIndices(vector<int>& nums, int target) {
    ranges::sort(nums);
    vector<int> result;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == target) {
        result.push_back(i);
      }
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> nums = {1, 2, 5, 2, 3};
  vector<int> result = sol.targetIndices(nums, 2);
  vector<int> result_expected = {1, 2};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums = {1, 2, 5, 2, 3};
  result = sol.targetIndices(nums, 3);
  result_expected = {3};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  nums = {1, 2, 5, 2, 3};
  result = sol.targetIndices(nums, 5);
  result_expected = {4};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}