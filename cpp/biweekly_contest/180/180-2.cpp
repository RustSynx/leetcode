//
// Created by Milo on 4/11/26.
//
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int countDigitOccurrences(vector<int>& nums, int digit) {
    int n = static_cast<int>(nums.size());
    int result = 0;
    for (int i = 0; i < n; i++) {
      string s = to_string(nums[i]);
      for (char c : s) {
        if (c - '0' == digit) {
          result++;
        }
      }
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> nums = {12, 54, 32, 22};
  int result = sol.countDigitOccurrences(nums, 2);
  int result_expected = 4;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums = {1, 34, 7};
  result = sol.countDigitOccurrences(nums, 9);
  result_expected = 0;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}