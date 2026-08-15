//
// Created by Milo on 8/15/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int longestSubsequence(vector<int>& nums) {
    bool non_zero = false;
    int xor_curr = 0;
    for (int n : nums) {
      if (n != 0) non_zero = true;
      xor_curr ^= n;
    }
    if (xor_curr != 0) return nums.size();
    if (non_zero) return nums.size() - 1;
    return 0;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> nums = {1, 2, 3};
  int result = sol.longestSubsequence(nums);
  int result_expected = 2;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums = {2, 3, 4};
  result = sol.longestSubsequence(nums);
  result_expected = 3;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}