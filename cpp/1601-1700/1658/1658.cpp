//
// Created by Milo on 9/23/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int n;
  int minOperations(vector<int>& nums, int x) {
    n = nums.size();
    int prefix_sum = 0;
    for (int num : nums) {
      prefix_sum += num;
    }
    int target = prefix_sum - x;
    if (target == 0) return n;
    if (target < 0) return -1;
    int max_step = -1;
    int left = 0;
    int curr_sum = 0;
    for (int right = 0; right < n; right++) {
      curr_sum += nums[right];
      while (curr_sum > target && left <= right) {
        curr_sum -= nums[left];
        left++;
      }
      if (curr_sum == target) {
        max_step = max(max_step, right - left + 1);
      }
    }
    return max_step == - 1 ? -1 : n - max_step;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> nums = {1, 1, 4, 2, 3};
  int result = sol.minOperations(nums, 5);
  int result_expected = 2;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums = {5, 6, 7, 8, 9};
  result = sol.minOperations(nums, 4);
  result_expected = -1;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  nums = {3, 2, 20, 1, 1, 3};
  result = sol.minOperations(nums, 10);
  result_expected = 5;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}