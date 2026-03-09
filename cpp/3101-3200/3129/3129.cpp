//
// Created by Milo on 3/9/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int numberOfStableArrays(int zero, int one, int limit) {
    int mod = 1e9 + 7;
    vector<vector<vector<int>>> memo(
        zero + 1, vector<vector<int>>(one + 1, vector<int>(2, 0)));
    for (int i = 0; i <= min(zero, limit); i++) {
      memo[i][0][0] = 1;
    }
    for (int i = 0; i <= min(one, limit); i++) {
      memo[0][i][1] = 1;
    }
    for (int i = 1; i <= zero; i++) {
      for (int j = 1; j <= one; j++) {
        long long temp = memo[i - 1][j][0] + memo[i - 1][j][1];

        if (i > limit) {
          temp -= memo[i - (limit + 1)][j][1];
        }
        memo[i][j][0] = (temp % mod + mod) % mod;

        temp = memo[i][j - 1][0] + memo[i][j - 1][1];

        if (j > limit) {
          temp -= memo[i][j - (limit + 1)][0];
        }
        memo[i][j][1] = (temp % mod + mod) % mod;
      }
    }
    return (memo[zero][one][0] + memo[zero][one][1]) % mod;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  int result = sol.numberOfStableArrays(1, 1, 2);
  int result_expected = 2;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.numberOfStableArrays(1, 2, 1);
  result_expected = 1;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  result = sol.numberOfStableArrays(3, 3, 2);
  result_expected = 14;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}