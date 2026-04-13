//
// Created by Milo on 4/13/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int getMinDistance(vector<int>& nums, int target, int start) {
    int n = static_cast<int>(nums.size());
    int result = INT_MAX;
    for (int i = 0; i < n; i++) {
      if (nums[i] == target) {
        result = min(result, abs(i - start));
      }
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> nums = {1, 2, 3, 4, 5};
  int result = sol.getMinDistance(nums, 5, 3);
  int result_expected = 1;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums = {1};
  result = sol.getMinDistance(nums, 1, 0);
  result_expected = 0;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  nums = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  result = sol.getMinDistance(nums, 1, 0);
  result_expected = 0;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}