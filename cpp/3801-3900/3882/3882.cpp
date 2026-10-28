//
// Created by Milo on 10/28/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int minCost(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<vector<bool>>> dp(m, vector<vector<bool>>(n, vector<bool>(1024, false)));
    dp[0][0][grid[0][0]] = true;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        for (int k = 0; k < 1024; k++) {
          if (dp[i][j][k]) {
            if (i + 1 < m) {
              dp[i + 1][j][k ^ grid[i + 1][j]] = true;
            }
            if (j + 1 < n) {
              dp[i][j + 1][k ^ grid[i][j + 1]] = true;
            }
          }
        }
      }
    }
    for (int i = 0; i < 1024; i++) {
      if (dp[m - 1][n - 1][i]) {
        return i;
      }
    }
    return 0;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<vector<int>> grid = {{1, 2}, {3, 4}};
  int result = sol.minCost(grid);
  int result_expected = 6;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  grid = {{6, 7}, {5, 8}};
  result = sol.minCost(grid);
  result_expected = 9;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  grid = {{2, 7, 5}};
  result = sol.minCost(grid);
  result_expected = 0;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  grid = {{0, 5, 0}, {2, 0, 7}};
  result = sol.minCost(grid);
  result_expected = 2;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}