//
// Created by Milo on 9/29/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

class Solution {
 public:
  int m;
  int n;
  bool hasValidPath(vector<vector<char>>& grid) {
    m = grid.size();
    n = grid[0].size();
    if ((m + n - 1) % 2 != 0) return false;
    if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(') return false;
    int max_b = (m + n) / 2;
    vector<vector<vector<bool>>> visited(
        m, vector<vector<bool>>(n, vector<bool>(max_b + 1, false)));
    return dfs(grid, 0, 0, 0, visited, max_b);
  }
  bool dfs(vector<vector<char>>& grid, int row, int col, int b_count,
           vector<vector<vector<bool>>>& visited, int max_b) {
    if (row >= m || col >= n) return false;
    if (grid[row][col] == '(')
      b_count++;
    else
      b_count--;
    int remain_steps = (m - 1 - row) + (n - 1 - col);
    if (b_count < 0 || b_count > max_b || b_count > remain_steps) return false;
    if (m - 1 == row && n - 1 == col) return b_count == 0;
    if (visited[row][col][b_count]) return false;
    visited[row][col][b_count] = true;
    return dfs(grid, row, col + 1, b_count, visited, max_b) ||
           dfs(grid, row + 1, col, b_count, visited, max_b);
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<vector<char>> grid = {
      {'(', '(', '('}, {')', '(', ')'}, {'(', '(', ')'}, {'(', '(', ')'}};
  bool result = sol.hasValidPath(grid);
  bool result_expected = true;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  grid = {{')', ')'}, {'(', '('}};
  result = sol.hasValidPath(grid);
  result_expected = false;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}