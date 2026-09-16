//
// Created by Milo on 9/16/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int numberOfSets(int n, int k) {
    int mod = 1e9 + 7;
    vector<vector<vector<long long>>> dp(
        n + 1, vector<vector<long long>>(k + 1, vector<long long>(2)));
    for (int i = 0; i < n; i++) {
      dp[i][0][0] = 1;
    }
    for (int i = 1; i < n; i++) {
      for (int j = 1; j <= k; j++) {
        dp[i][j][1] = (dp[i - 1][j][1] + dp[i - 1][j - 1][0]) % mod;
        dp[i][j][0] = (dp[i - 1][j][0] + dp[i][j][1]) % mod;
      }
    }
    return dp[n - 1][k][0];
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  int result = sol.numberOfSets(4, 2);
  int result_expected = 5;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.numberOfSets(3, 1);
  result_expected = 3;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  result = sol.numberOfSets(30, 7);
  result_expected = 796297179;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}