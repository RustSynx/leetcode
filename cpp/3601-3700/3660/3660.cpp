//
// Created by Milo on 5/7/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> maxValue(vector<int>& nums) {
    int n = static_cast<int>(nums.size());
    vector<int> left_max(n);
    left_max[0] = nums[0];
    for (int i = 0; i < n - 1; i++) {
      if (left_max[i] > nums[i + 1]) {
        left_max[i + 1] = left_max[i];
      } else {
        left_max[i + 1] = nums[i + 1];
      }
    }
    vector<int> right_min(n);
    right_min[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; i--) {
      right_min[i] = min(right_min[i + 1], nums[i]);
    }
    vector<int> max_idx_vec;
    max_idx_vec.push_back(0);
    for (int i = 1; i < n; i++) {
      if (left_max[i] > left_max[i - 1]) {
        max_idx_vec.push_back(i);
      }
    }
    vector<int> result(n);
    result[max_idx_vec.back()] = nums[max_idx_vec.back()];
    for (int i = static_cast<int>(max_idx_vec.size()) - 2; i >= 0; i--) {
      int current_idx = max_idx_vec[i];
      int next_idx = max_idx_vec[i+1];
      if (next_idx + 1 < n && nums[current_idx] > right_min[next_idx + 1]) {
        result[current_idx] = result[next_idx];
      } else {
        result[current_idx] = nums[current_idx];
      }
    }
    int max_idx = 0;
    for (int i = 0; i < n; i++) {
      if (max_idx + 1 < max_idx_vec.size() && i == max_idx_vec[max_idx + 1]) {
        max_idx++;
      }
      result[i] = result[max_idx_vec[max_idx]];
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> nums = {2, 1, 3};
  vector<int> result = sol.maxValue(nums);
  vector<int> result_expected = {2, 2, 3};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums = {2, 3, 1};
  result = sol.maxValue(nums);
  result_expected = {3, 3, 3};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}