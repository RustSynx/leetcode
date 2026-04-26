//
// Created by Milo on 4/26/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> findValidElements(vector<int>& nums) {
    int n = static_cast<int>(nums.size());
    vector<int> result;
    result.reserve(n);
    for (int i = 0; i < n; i++) {
      if (i == 0 || i == n - 1) {
        result.push_back(nums[i]);
        continue;
      }
      bool condition = true;
      for (int j = 0; j < i; j++) {
        if (nums[j] >= nums[i]) {
          condition = false;
          break;
        }
      }
      if (condition) {
        result.push_back(nums[i]);
        continue;
      }
      condition = true;
      for (int j = i + 1; j < n; j++) {
        if (nums[j] >= nums[i]) {
          condition = false;
          break;
        }
      }
      if (condition) result.push_back(nums[i]);
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> nums = {1, 2, 4, 2, 3, 2};
  vector<int> result = sol.findValidElements(nums);
  vector<int> result_expected = {1, 2, 4, 3, 2};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums = {5, 5, 5, 5};
  result = sol.findValidElements(nums);
  result_expected = {5, 5};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  nums = {1};
  result = sol.findValidElements(nums);
  result_expected = {1};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}