//
// Created by Milo on 9/6/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int numDistinct(string s, string t) {
    int sn = s.length();
    int tn = t.length();
    if (tn > sn) return 0;
    vector<vector<unsigned long long>> dp(sn + 1, vector<unsigned long long>(tn + 1));
    for (int i = 0; i <= sn; i++) {
      dp[i][0] = 1;
    }
    for (int i = 1; i <= sn; i++) {
      for (int j = 1; j <= tn; j++) {
        if (s[i - 1] == t[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        } else {
          dp[i][j] = dp[i - 1][j];
        }
      }
    }
    return dp[sn][tn];
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  int result = sol.numDistinct("rabbbit", "rabbit");
  int result_expected = 3;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.numDistinct("babgbag", "bag");
  result_expected = 5;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}