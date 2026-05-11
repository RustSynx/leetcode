//
// Created by Milo on 5/11/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> separateDigits(vector<int>& nums) {
    int n = static_cast<int>(nums.size());
    vector<int> result;
    for (int i = n - 1; i >=0; i--) {
      int num = nums[i];
      while (num > 0) {
        result.push_back(num % 10);
        num /= 10;
      }
    }
    ranges::reverse(result);
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> nums = {13, 25, 83, 77};
  vector<int> result = sol.separateDigits(nums);
  vector<int> result_expected = {1, 3, 2, 5, 8, 3, 7, 7};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums = {7, 1, 3, 9};
  result = sol.separateDigits(nums);
  result_expected = {7, 1, 3, 9};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}