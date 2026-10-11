//
// Created by Milo on 10/11/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int sumOfSquares(vector<int>& nums) {
    int n = nums.size();
    int result = 0;
    for (int i = 1; i <= n; i++) {
      if (n % i == 0) {
        result += nums[i - 1] * nums[i - 1];
      }
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> nums = {1, 2, 3, 4};
  int result = sol.sumOfSquares(nums);
  int result_expected = 21;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums = {2, 7, 1, 19, 18, 3};
  result = sol.sumOfSquares(nums);
  result_expected = 63;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}