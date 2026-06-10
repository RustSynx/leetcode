//
// Created by Milo on 6/9/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  long long maxTotalValue(vector<int>& nums, int k) {
    long long max_val = *max_element(nums.begin(), nums.end());
    long long min_val = *min_element(nums.begin(), nums.end());
    return (max_val - min_val) * k;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> nums = {1, 3, 2};
  long long result = sol.maxTotalValue(nums, 2);
  long long result_expected = 4;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums = {4, 2, 5, 1};
  result = sol.maxTotalValue(nums, 3);
  result_expected = 12;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}