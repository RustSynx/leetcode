//
// Created by Milo on 10/15/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int sumCounts(vector<int>& nums) {
    int n = nums.size();
    int result = 0;
    for (int i = 0; i < n; i++) {
      bool d_c[101] = {false};
      int sum = 0;
      for (int j = i; j < n; j++) {
        if (!d_c[nums[j]]) {
          d_c[nums[j]] = true;
          sum++;
        }
        result += sum * sum;
      }
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> nums = {1, 2, 1};
  int result = sol.sumCounts(nums);
  int result_expected = 15;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums = {1, 1};
  result = sol.sumCounts(nums);
  result_expected = 3;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}