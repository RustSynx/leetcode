//
// Created by Milo on 7/25/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxProduct(int n) {
    vector<int> nums;
    nums.reserve(10);
    while (n > 0) {
      nums.push_back(n % 10);
      n /= 10;
    }
    ranges::sort(nums, greater<int>());
    return nums[0] * nums[1];
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  int result = sol.maxProduct(31);
  int result_expected = 3;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.maxProduct(22);
  result_expected = 4;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  result = sol.maxProduct(124);
  result_expected = 8;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}