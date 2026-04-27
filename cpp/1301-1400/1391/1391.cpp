//
// Created by Milo on 4/27/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int m, n;
  bool hasValidPath(vector<vector<int>>& grid) {
    m = static_cast<int>(grid.size());
    n = static_cast<int>(grid[0].size());
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    return findPath(grid, visited, 0, 0);
  }
  bool findPath(vector<vector<int>>& grid, vector<vector<bool>>& visited,
                int row, int col) {
    visited[row][col] = true;
    if (row == m - 1 && col == n - 1) return true;
    if (col + 1 < n && !visited[row][col + 1] &&
        nextPossible("RIGHT", grid[row][col], grid[row][col + 1])) {
      if (findPath(grid, visited, row, col + 1)) return true;
    }
    if (col - 1 >= 0 && !visited[row][col - 1] &&
        nextPossible("LEFT", grid[row][col], grid[row][col - 1])) {
      if (findPath(grid, visited, row, col - 1)) return true;
    }
    if (row - 1 >= 0 && !visited[row - 1][col] &&
        nextPossible("UP", grid[row][col], grid[row - 1][col])) {
      if (findPath(grid, visited, row - 1, col)) return true;
    }
    if (row + 1 < m && !visited[row + 1][col] &&
        nextPossible("DOWN", grid[row][col], grid[row + 1][col])) {
      if (findPath(grid, visited, row + 1, col)) return true;
    }
    return false;
  }
  bool nextPossible(string direction, int current_street, int next_street) {
    if (direction == "UP") {
      switch (current_street) {
        case 2:
        case 5:
        case 6:
          return next_street == 2 || next_street == 3 || next_street == 4;
        default:
          return false;
      }
    } else if (direction == "DOWN") {
      switch (current_street) {
        case 2:
        case 3:
        case 4:
          return next_street == 2 || next_street == 5 || next_street == 6;
        default:
          return false;
      }
    } else if (direction == "LEFT") {
      switch (current_street) {
        case 1:
        case 3:
        case 5:
          return next_street == 1 || next_street == 4 || next_street == 6;
        default:
          return false;
      }
    } else {
      switch (current_street) {
        case 1:
        case 4:
        case 6:
          return next_street == 1 || next_street == 3 || next_street == 5;
        default:
          return false;
      }
    }
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<vector<int>> grid = {{2, 4, 3}, {6, 5, 2}};
  bool result = sol.hasValidPath(grid);
  bool result_expected = true;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  grid = {{1, 2, 1}, {1, 2, 1}};
  result = sol.hasValidPath(grid);
  result_expected = false;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  grid = {{1, 1, 2}};
  result = sol.hasValidPath(grid);
  result_expected = false;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}