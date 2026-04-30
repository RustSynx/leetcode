//
// Created by Milo on 4/30/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  int m, n;
  vector<vector<vector<int>>> memo;

 public:
  int maxPathScore(vector<vector<int>>& grid, int k) {
    m = static_cast<int>(grid.size());
    n = static_cast<int>(grid[0].size());
    k = min(k, m + n - 1);
    memo.assign(m, vector<vector<int>>(n, vector<int>(k + 1, -2)));
    return findPathScore(grid, k, 0, 0);
  }
  int findPathScore(vector<vector<int>>& grid, int k, int row, int col) {
    if (row >= m || col >= n) return -1;
    k -= getCost(grid[row][col]);
    if (k < 0) return -1;
    if (row == m - 1 && col == n - 1) return grid[row][col];
    if (memo[row][col][k] != -2) return memo[row][col][k];
    int right = findPathScore(grid, k, row, col + 1);
    int down = findPathScore(grid, k, row + 1, col);
    int max_value = max(right, down);
    if (max_value == -1) {
      return memo[row][col][k] = -1;
    }
    return memo[row][col][k] = grid[row][col] + max_value;
  }
  int getCost(int num) {
    switch (num) {
      case 1:
      case 2:
        return 1;
      default:
        return 0;
    }
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<vector<int>> grid = {{0, 1}, {2, 0}};
  int result = sol.maxPathScore(grid, 1);
  int result_expected = 2;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  grid = {{0, 1}, {1, 2}};
  result = sol.maxPathScore(grid, 1);
  result_expected = -1;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}