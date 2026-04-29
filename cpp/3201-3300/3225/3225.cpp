//
// Created by Milo on 4/29/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  long long memo[101][101][101];
  long long maximumScore(vector<vector<int>>& grid) {
    memset(memo, 0, sizeof(memo));
    int m = static_cast<int>(grid.size());
    int n = static_cast<int>(grid[0].size());
    if (n == 1) return 0;
    vector<vector<long long>> prefix(n, vector<long long>(m + 1, 0));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        prefix[i][j + 1] = prefix[i][j] + grid[j][i];
      }
    }
    for (int curr = 0; curr <= m; curr++) {
      for (int prev = 0; prev <= m; prev++) {
        long long extra_score = 0;
        if (curr > prev) {
          extra_score = prefix[0][curr] - prefix[0][prev];
        } else if (curr < prev) {
          extra_score = prefix[1][prev] - prefix[1][curr];
        }
        memo[1][curr][prev] = extra_score;
      }
    }
    for (int i = 2; i < n; i++) {
      for (int prev = 0; prev <= m; prev++) {
        long long max_memo_all = -1e15;
        long long base_max = -1e15;
        vector<long long> suffix_max(m + 2, -1e15);
        for (int pp = 0; pp <= m; pp++) {
          max_memo_all = max(max_memo_all, memo[i - 1][prev][pp]);
          if (pp < prev) {
            base_max = max(base_max, memo[i - 1][prev][pp]);
          }
        }
        for (int pp = m; pp >= 0; pp--) {
          suffix_max[pp] = max(suffix_max[pp + 1], memo[i - 1][prev][pp]);
        }
        long long running_max = -1e15;
        for (int curr = 0; curr <= m; curr++) {
          if (curr < prev) {
            memo[i][curr][prev] = max_memo_all + prefix[i][prev] - prefix[i][curr];
          } else {
            if (curr > prev) {
              int pp = curr - 1;
              running_max = max(running_max, memo[i - 1][prev][pp] - prefix[i - 1][pp]);
            }
            long long v1 = (base_max != -1e15) ? base_max - prefix[i - 1][prev] + prefix[i - 1][curr] : -1e15;
            long long v2 = (running_max != -1e15) ? running_max + prefix[i - 1][curr] : -1e15;
            long long v3 = suffix_max[curr];
            memo[i][curr][prev] = max({v1, v2, v3});
          }
        }
      }
    }
    long long result = 0;
    for (int curr = 0; curr <= m; curr++) {
      for (int prev = 0; prev <= m; prev++) {
        result = max(result, memo[n - 1][curr][prev]);
      }
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<vector<int>> grid = {{0, 0, 0, 0, 0},
                              {0, 0, 3, 0, 0},
                              {0, 1, 0, 0, 0},
                              {5, 0, 0, 3, 0},
                              {0, 0, 0, 0, 2}};
  int result = sol.maximumScore(grid);
  int result_expected = 11;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  grid = {{10, 9, 0, 0, 15},
          {7, 1, 0, 8, 0},
          {5, 20, 0, 11, 0},
          {0, 0, 0, 1, 2},
          {8, 12, 1, 10, 3}};
  result = sol.maximumScore(grid);
  result_expected = 94;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}