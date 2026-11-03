//
// Created by Milo on 11/3/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int minMoves(vector<int>& nums) {
    int max_n = *max_element(nums.begin(), nums.end());
    int result = 0;
    for (int n : nums) {
      result += max_n - n;
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> nums = {2, 1, 3};
  int result = sol.minMoves(nums);
  int result_expected = 3;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums = {4,4,5};
  result = sol.minMoves(nums);
  result_expected = 2;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}