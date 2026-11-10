//
// Created by Milo on 11/10/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int climbStairs(int n, vector<int>& costs) {
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 0; i + 1 <= n; i++) {
      int step = costs[i] + 1;
      dp[i + 1] = min(dp[i + 1], dp[i] + step);
      if (i + 2 <= n) {
        step = costs[i + 1] + 4;
        dp[i + 2] = min(dp[i + 2], dp[i] + step);
      }
      if (i + 3 <= n) {
        step = costs[i + 2] + 9;
        dp[i + 3] = min(dp[i + 3], dp[i] + step);
      }
    }
    return dp[n];
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> costs = {1, 2, 3, 4};
  long long result = sol.climbStairs(4, costs);
  long long result_expected = 13;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  costs = {5, 1, 6, 2};
  result = sol.climbStairs(4, costs);
  result_expected = 11;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  costs = {9, 8, 3};
  result = sol.climbStairs(3, costs);
  result_expected = 12;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}