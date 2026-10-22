//
// Created by Milo on 10/22/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int minOperations(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return 0;
    int zero_idx = -1;
    int up_down_count[2] = {0};
    for (int i = 0; i < n; i++) {
      if (nums[i] == 0) zero_idx = i;
      if (nums[i] < nums[(i + 1) % n]) {
        up_down_count[0]++;
      } else {
        up_down_count[1]++;
      }
    }
    if (up_down_count[1] == 1) {
      return min(zero_idx, n - zero_idx + 2);
    }
    if (up_down_count[0] == 1) {
      return min(n - zero_idx, zero_idx + 2);
    }
    return -1;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> nums = {0, 2, 1};
  int result = sol.minOperations(nums);
  int result_expected = 2;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums = {1, 0, 2};
  result = sol.minOperations(nums);
  result_expected = 2;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  nums = {2, 0, 1, 3};
  result = sol.minOperations(nums);
  result_expected = -1;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}