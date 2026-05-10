//
// Created by Milo on 5/10/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  int n;
  int memo[1001];

 public:
  int maximumJumps(vector<int>& nums, int target) {
    n = static_cast<int>(nums.size());
    memset(memo, -1, sizeof(memo));
    memo[0] = 0;
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (memo[j] != -1 && abs(static_cast<long long>(nums[i]) - nums[j]) <= target) {
          memo[i] = max(memo[i], memo[j] + 1);
        }
      }
    }
    return memo[n-1];
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> nums = {1, 3, 6, 4, 1, 2};
  int result = sol.maximumJumps(nums, 2);
  int result_expected = 3;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums = {1, 3, 6, 4, 1, 2};
  result = sol.maximumJumps(nums, 3);
  result_expected = 5;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  nums = {1, 3, 6, 4, 1, 2};
  result = sol.maximumJumps(nums, 0);
  result_expected = -1;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}