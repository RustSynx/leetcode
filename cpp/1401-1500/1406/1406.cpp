//
// Created by Milo on 8/3/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  string stoneGameIII(vector<int>& stoneValue) {
    int n = stoneValue.size();

    vector<int> dp(n + 1, INT_MIN);
    dp[n] = 0;

    for (int i = n - 1; i >= 0; i--) {
      int curr = 0;
      for (int j = 1; j < 4; j++) {
        if (i + j - 1 < n) {
          curr += stoneValue[i + j - 1];
          dp[i] = max(dp[i], curr - dp[i + j]);
        }
      }
    }
    return dp[0] > 0 ? "Alice" : dp[0] < 0 ? "Bob" : "Tie";
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> stoneValue = {1, 2, 3, 7};
  string result = sol.stoneGameIII(stoneValue);
  string result_expected = "Bob";
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  stoneValue = {1, 2, 3, -9};
  result = sol.stoneGameIII(stoneValue);
  result_expected = "Alice";
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  stoneValue = {1, 2, 3, 6};
  result = sol.stoneGameIII(stoneValue);
  result_expected = "Tie";
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}