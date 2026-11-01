//
// Created by Milo on 11/1/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int minMoves(vector<int>& nums) {
    int result = 0;
    int min_n = *min_element(nums.begin(), nums.end());
    for (int n : nums) {
      result += n - min_n;
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> nums = {1, 2, 3};
  int result = sol.minMoves(nums);
  int result_expected = 3;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums = {1, 1, 1};
  result = sol.minMoves(nums);
  result_expected = 0;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}