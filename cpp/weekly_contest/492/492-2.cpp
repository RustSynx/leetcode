//
// Created by Milo on 3/8/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

class Solution {
 public:
  int smallestBalancedIndex(vector<int>& nums) {
    long long left_sum = 0;
    long long right_sum = 1;
    if (nums.size() < 2) return -1;
    for (int num : nums) {
      left_sum += num;
    }
    for (int i = static_cast<int>(nums.size()) - 1; i >= 0; i--) {
      left_sum -= nums[i];
      if (i + 1 <= nums.size() - 1) {
        if (left_sum / nums[i + 1] < right_sum) {
          return -1;
        }
        right_sum *= nums[i + 1];
      }
      if (left_sum == right_sum) return i;
    }
    return -1;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> input = {2, 1, 2};
  int result = sol.smallestBalancedIndex(input);
  int result_expected = 1;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  input = {2, 8, 2, 2, 5};
  result = sol.smallestBalancedIndex(input);
  result_expected = 2;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  input = {1};
  result = sol.smallestBalancedIndex(input);
  result_expected = -1;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}