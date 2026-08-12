//
// Created by Milo on 8/12/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxSubarrayLength(vector<int>& nums, int k) {
    int n = nums.size();
    unordered_map<int, int> map;
    int result = 0;
    int left = 0;
    int right = 0;
    while (left <= right && right < n) {
      int right_num = nums[right];
      int left_num = nums[left];
      if (map[right_num] < k) {
        result = max(result, right - left + 1);
        map[right_num]++;
        right++;
      } else {
        map[left_num]--;
        left++;
      }
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> nums = {1, 2, 3, 1, 2, 3, 1, 2};
  int result = sol.maxSubarrayLength(nums, 2);
  int result_expected = 6;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums = {1, 2, 1, 2, 1, 2, 1, 2};
  result = sol.maxSubarrayLength(nums, 1);
  result_expected = 2;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  nums = {5, 5, 5, 5, 5, 5, 5};
  result = sol.maxSubarrayLength(nums, 4);
  result_expected = 4;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}