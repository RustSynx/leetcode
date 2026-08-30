//
// Created by Milo on 8/30/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int minimumDeletions(vector<int>& nums) {
    int n = nums.size();
    int max_n = INT_MIN;
    int max_i = 0;
    int min_n = INT_MAX;
    int min_i = 0;
    for (int i = 0; i < n; i++) {
      int curr = nums[i];
      if (max_n < curr) {
        max_n = curr;
        max_i = i;
      }
      if (min_n > curr) {
        min_n = curr;
        min_i = i;
      }
    }
    if (min_i < max_i) {
      int result = max_i + 1;
      result = min(result, n - min_i);
      result = min(result, min_i + 1 + n - max_i);
      return result;
    }
    int result = min_i + 1;
    result = min(result, n - max_i);
    result = min(result, max_i + 1 + n - min_i);
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> nums = {2, 10, 7, 5, 4, 1, 8, 6};
  int result = sol.minimumDeletions(nums);
  int result_expected = 5;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums = {0, -4, 19, 1, 8, -2, -3, 5};
  result = sol.minimumDeletions(nums);
  result_expected = 3;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  nums = {101};
  result = sol.minimumDeletions(nums);
  result_expected = 1;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}