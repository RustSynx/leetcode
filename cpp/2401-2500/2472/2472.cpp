//
// Created by Milo on 9/15/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxPalindromes(string s, int k) {
    int n = s.length();
    vector<vector<bool>> is_pal(n, vector<bool>(n));
    for (int i = 0; i < n; i++) {
      is_pal[i][i] = true;
    }
    for (int i = 0; i < n - 1; i++) {
      if (s[i] == s[i + 1]) {
        is_pal[i][i + 1] = true;
      }
    }
    for (int len = 3; len <= n; len++) {
      for (int i = 0; i <= n - len; i++) {
        int j = i + len - 1;
        if (s[i] == s[j] && is_pal[i + 1][j - 1]) {
          is_pal[i][j] = true;
        }
      }
    }
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      dp[i] = dp[i - 1];
      for (int j = 0; j <= i - k; j++) {
        if (is_pal[j][i - 1]) {
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }
    }
    return dp[n];
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  int result = sol.maxPalindromes("abaccdbbd", 3);
  int result_expected = 2;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.maxPalindromes("adbcda", 2);
  result_expected = 0;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}