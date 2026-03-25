//
// Created by Milo on 3/25/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  bool canPartitionGrid(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<long long>> prefix_sum(m, vector<long long>(n, 0));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (i > 0) {
          if (j > 0) {
            prefix_sum[i][j] = prefix_sum[i-1][j] + prefix_sum[i][j-1] + grid[i][j] - prefix_sum[i-1][j-1] ;
          } else {
            prefix_sum[i][j] = prefix_sum[i-1][j] + grid[i][j];
          }
        } else {
          if (j > 0) {
            prefix_sum[i][j] = prefix_sum[i][j-1] + grid[i][j];
          } else {
            prefix_sum[i][j] = grid[i][j];
          }
        }
      }
    }
    if (prefix_sum[m-1][n-1] % 2 != 0) return false;
    long long sum = 0;
    for (int i = 0; i < m - 1; i++) {
      sum = prefix_sum[i][n-1];
      if (sum == prefix_sum[m-1][n-1] / 2) {
        return true;
      }
    }
    for (int i = 0; i < n - 1; i++) {
      sum = prefix_sum[m-1][i];
      if (sum == prefix_sum[m-1][n-1] / 2) {
        return true;
      }
    }
    return false;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<vector<int>> input = {{1, 4}, {2, 3}};
  bool result = sol.canPartitionGrid(input);
  bool result_expected = true;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  input = {{1, 3}, {2, 4}};
  result = sol.canPartitionGrid(input);
  result_expected = false;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}