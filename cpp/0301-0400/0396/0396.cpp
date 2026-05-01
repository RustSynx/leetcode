//
// Created by Milo on 5/1/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

class Solution {
 public:
  int maxRotateFunction(vector<int>& nums) {
    int n = static_cast<int>(nums.size());
    long long sum = 0;
    long long prev_f = 0;
    for (long long i = 0; i < n; i++) {
      sum += nums[i];
      prev_f += nums[i] * i;
    }
    long long result = prev_f;
    for (int i = 1; i < n; i++) {
      prev_f = prev_f + sum - (n * nums[n - i]);
      result = max(result, prev_f);
    }
    return static_cast<int>(result);
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> nums = {4, 3, 2, 6};
  int result = sol.maxRotateFunction(nums);
  int result_expected = 26;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums = {100};
  result = sol.maxRotateFunction(nums);
  result_expected = 0;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}