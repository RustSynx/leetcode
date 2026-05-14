//
// Created by Milo on 5/14/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool isGood(vector<int>& nums) {
    if (nums.size() == 1) return false;
    sort(nums.begin(), nums.end());
    int n = static_cast<int>(nums.size()) - 1;
    if (nums[n] != nums[n-1]) return false;
    for (int i = n - 1; i >= 0; i--) {
      if (nums[i] != i + 1) return false;
    }
    return true;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> nums = {2, 1, 3};
  bool result = sol.isGood(nums);
  bool result_expected = false;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums = {1, 3, 3, 2};
  result = sol.isGood(nums);
  result_expected = true;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  nums = {1, 1};
  result = sol.isGood(nums);
  result_expected = true;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  nums = {3, 4, 4, 1, 2, 1};
  result = sol.isGood(nums);
  result_expected = false;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}