//
// Created by Milo on 11/14/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int minimumSumSubarray(vector<int>& nums, int l, int r) {
    int n = nums.size();
    int result = INT_MAX;
    for (int i = 0; i < n; i++) {
      int sum = 0;
      for (int j = i; j < n; j++) {
        int len = j - i + 1;
        if (len > r) break;
        sum += nums[j];
        if (len >= l && sum > 0) {
          result = min(result, sum);
        }
      }
    }
    return result == INT_MAX ? -1 : result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> nums = {3, -2, 1, 4};
  int result = sol.minimumSumSubarray(nums, 2, 3);
  int result_expected = 1;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums = {-2, 2, -3, 1};
  result = sol.minimumSumSubarray(nums, 2, 3);
  result_expected = -1;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  nums = {1, 2, 3, 4};
  result = sol.minimumSumSubarray(nums, 2, 4);
  result_expected = 3;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}