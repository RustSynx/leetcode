//
// Created by Milo on 11/24/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
 public:
  int maxLength(vector<int>& nums) {
    int n = nums.size();
    int result = 2;
    for (int i = 0; i < n; i++) {
      int total_gcd = nums[i];
      int total_lcm = nums[i];
      int total_prod = nums[i];
      for (int j = i + 1; j < n; j++) {
        total_gcd = gcd(total_gcd, nums[j]);
        total_lcm = lcm(total_lcm, nums[j]);
        total_prod *= nums[j];
        if (total_prod > 25200) {
          break;
        }
        if (total_prod == total_gcd * total_lcm) {
          result = max(result, j - i + 1);
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
  vector<int> nums = {1, 2, 1, 2, 1, 1, 1};
  int result = sol.maxLength(nums);
  int result_expected = 5;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums = {2, 3, 4, 5, 6};
  result = sol.maxLength(nums);
  result_expected = 3;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  nums = {1, 2, 3, 1, 4, 5, 1};
  result = sol.maxLength(nums);
  result_expected = 5;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}