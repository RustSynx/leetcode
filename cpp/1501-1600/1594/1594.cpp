//
// Created by Milo on 3/23/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

class Solution {
public:
  int maxProductPath(vector<vector<int>>& grid) {
    long long mod = 1e9 + 7;
    int m = static_cast<int>(grid.size());
    int n = static_cast<int>(grid[0].size());
    vector<vector<long long>> min_memo(m, vector<long long>(n, 0));
    vector<vector<long long>> max_memo(m, vector<long long>(n, 0));
    max_memo[0][0] = min_memo[0][0] = grid[0][0];
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (i == 0 && j == 0) continue;
        long long down_max = LLONG_MIN;
        long long down_min = LLONG_MAX;
        if (i > 0) {
          down_max = max(max_memo[i-1][j] * grid[i][j], min_memo[i-1][j] * grid[i][j]);
          down_min = min(max_memo[i-1][j] * grid[i][j], min_memo[i-1][j] * grid[i][j]);
        }
        long long right_max = LLONG_MIN;
        long long right_min = LLONG_MAX;
        if (j > 0) {
          right_max = max(max_memo[i][j-1] * grid[i][j], min_memo[i][j-1] * grid[i][j]);
          right_min = min(max_memo[i][j-1] * grid[i][j], min_memo[i][j-1] * grid[i][j]);
        }
        max_memo[i][j] = max(down_max, right_max);
        min_memo[i][j] = min(down_min, right_min);
      }
    }
    return max_memo[m-1][n-1] < 0 ? -1 : max_memo[m-1][n-1] % mod;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<vector<int>> input = {{-1,-2,-3},{-2,-3,-3},{-3,-3,-2}};
  int result = sol.maxProductPath(input);
  int result_expected = -1;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  input = {{1,-2,1},{1,-2,1},{3,-4,1}};
  result = sol.maxProductPath(input);
  result_expected = 8;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  input = {{1,3},{0,-4}};
  result = sol.maxProductPath(input);
  result_expected = 0;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}