//
// Created by Milo on 8/11/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int missingInteger(vector<int>& nums) {
    int n = nums.size();
    int prefix_sum = nums[0];
    for (int i = 1; i < n; i++) {
      if (nums[i - 1] + 1 == nums[i]) {
        prefix_sum += nums[i];
      } else {
        break;
      }
    }
    while (find(nums.begin(), nums.end(), prefix_sum) != nums.end()) {
      prefix_sum++;
    }
    return prefix_sum;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> nums = {1, 2, 3, 2, 5};
  int result = sol.missingInteger(nums);
  int result_expected = 6;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums = {3, 4, 5, 1, 12, 14, 13};
  result = sol.missingInteger(nums);
  result_expected = 15;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}