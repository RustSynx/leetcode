//
// Created by Milo on 10/25/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int m;
  int n;
  int closedIsland(vector<vector<int>>& grid) {
    m = grid.size();
    n = grid[0].size();
    int result = 0;
    for (int i = 0; i < n; i++) {
      if (grid[0][i] == 0) {
        dfs(grid, 0, i);
      }
      if (grid[m - 1][i] == 0) {
        dfs(grid, m - 1, i);
      }
    }
    for (int i = 0; i < m; i++) {
      if (grid[i][0] == 0) {
        dfs(grid, i, 0);
      }
      if (grid[i][n - 1] == 0) {
        dfs(grid, i, n - 1);
      }
    }
    for (int i = 1; i < m - 1; i++) {
      for (int j = 1; j < n - 1; j++) {
        if (grid[i][j] == 0) {
          result++;
          dfs(grid, i, j);
        }
      }
    }
    return result;
  }
  void dfs(vector<vector<int>>& grid, int row, int col) {
    if (row < 0 || col < 0 || row > m - 1 || col > n - 1 || grid[row][col] == 1) return;
    grid[row][col] = 1;
    dfs(grid, row - 1, col);
    dfs(grid, row + 1, col);
    dfs(grid, row, col - 1);
    dfs(grid, row, col + 1);
  }
};
int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<vector<int>> grid = {{1, 1, 1, 1, 1, 1, 1, 0},
                              {1, 0, 0, 0, 0, 1, 1, 0},
                              {1, 0, 1, 0, 1, 1, 1, 0},
                              {1, 0, 0, 0, 0, 1, 0, 1},
                              {1, 1, 1, 1, 1, 1, 1, 0}};
  int result = sol.closedIsland(grid);
  int result_expected = 2;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  grid = {{0, 0, 1, 0, 0}, {0, 1, 0, 1, 0}, {0, 1, 1, 1, 0}};
  result = sol.closedIsland(grid);
  result_expected = 1;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  grid = {{1, 1, 1, 1, 1, 1, 1}, {1, 0, 0, 0, 0, 0, 1}, {1, 0, 1, 1, 1, 0, 1},
          {1, 0, 1, 0, 1, 0, 1}, {1, 0, 1, 1, 1, 0, 1}, {1, 0, 0, 0, 0, 0, 1},
          {1, 1, 1, 1, 1, 1, 1}};
  result = sol.closedIsland(grid);
  result_expected = 2;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}