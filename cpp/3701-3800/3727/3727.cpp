//
// Created by Milo on 10/13/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  long long maxAlternatingSum(vector<int>& nums) {
    int n = nums.size();
    int neg_pos = n / 2;
    ranges::nth_element(nums.begin(), nums.begin() + neg_pos, nums.end(),
                [](int a, int b) { return abs(a) < abs(b); });
    long long result = 0;
    for (int i = 0; i < neg_pos; i++) {
      result -= nums[i] * nums[i];
    }
    for (int i = neg_pos; i < n; i++) {
      result += nums[i] * nums[i];
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector nums = {1, 2, 3};
  long long result = sol.maxAlternatingSum(nums);
  long long result_expected = 12;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums = {1, -1, 2, -2, 3, -3};
  result = sol.maxAlternatingSum(nums);
  result_expected = 16;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}