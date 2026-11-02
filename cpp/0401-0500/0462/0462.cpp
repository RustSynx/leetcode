//
// Created by Milo on 11/2/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int minMoves2(vector<int>& nums) {
    ranges::sort(nums);
    int mid = nums[nums.size() / 2];
    int result = 0;
    for (int n : nums) {
      result += abs(mid - n);
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> nums = {1, 2, 3};
  int result = sol.minMoves2(nums);
  int result_expected = 2;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums = {1, 10, 2, 9};
  result = sol.minMoves2(nums);
  result_expected = 16;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}