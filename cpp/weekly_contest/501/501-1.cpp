//
// Created by Milo on 5/10/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> concatWithReverse(vector<int>& nums) {
    int n = static_cast<int>(nums.size());
    vector<int> result(n * 2);
    for (int i = 0; i < n * 2; i++) {
      if (i < n) {
        result[i] = nums[i];
      } else {
        result[i] = nums[n - (i - n) - 1];
      }
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> nums = {1, 2, 3};
  vector<int> result = sol.concatWithReverse(nums);
  vector<int> result_expected = {1, 2, 3, 3, 2, 1};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums = {1};
  result = sol.concatWithReverse(nums);
  result_expected = {1, 1};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}