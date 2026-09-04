//
// Created by Milo on 9/4/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int firstStableIndex(vector<int>& nums, int k) {
    int n = nums.size();
    int max_val = nums[0];
    vector<int> right_min(n);
    right_min[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; i--) {
      right_min[i] = min(right_min[i + 1], nums[i]);
    }
    for (int i = 0; i < n; i++) {
      if (nums[i] > max_val) max_val = nums[i];
      if (max_val - right_min[i] <= k) return i;
    }
    return -1;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> nums = {5, 0, 1, 4};
  int result = sol.firstStableIndex(nums, 3);
  int result_expected = 3;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums = {3, 2, 1};
  result = sol.firstStableIndex(nums, 1);
  result_expected = -1;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  nums = {0};
  result = sol.firstStableIndex(nums, 0);
  result_expected = 0;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}