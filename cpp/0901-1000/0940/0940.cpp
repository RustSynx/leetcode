//
// Created by Milo on 9/7/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
  int distinctSubseqII(string s) {
    int n = s.length();
    int mod = 1e9 + 7;
    int last_idx[26];
    memset(last_idx, -1, sizeof(last_idx));
    vector<long long> dp(n + 1);
    dp[0] = 1;
    last_idx[s[0] - 'a'] = 0;
    for (int i = 1; i < n; i++) {
      dp[i] = (dp[i - 1] * 2 + 1) % mod;
      int idx = last_idx[s[i] - 'a'];
      if (idx != -1) {
        long long duplicate = idx - 1 >= 0 ? dp[idx - 1] + 1 : 1;
        dp[i] = (dp[i] - duplicate % mod + mod) % mod;
      }
      last_idx[s[i] - 'a'] = i;
    }
    return dp[n - 1];
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  int result = sol.distinctSubseqII("abc");
  int result_expected = 7;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.distinctSubseqII("aba");
  result_expected = 6;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  result = sol.distinctSubseqII("aaa");
  result_expected = 3;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}