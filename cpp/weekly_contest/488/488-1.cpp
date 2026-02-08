//
// Created by Milo on 2/5/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
  int dominantIndices(vector<int>& nums) {
    int result = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (i == nums.size() - 1) {
        break;
      }
      int average = accumulate(nums.begin() + i, nums.end(), 0) / (nums.size() - i);
      if (nums[i] > average) {
        result++;
      }
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> nums = {5, 4, 3};
  int result = sol.dominantIndices(nums);
  int result_expected = 2;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums = {4, 1, 2};
  result = sol.dominantIndices(nums);
  result_expected = 1;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}