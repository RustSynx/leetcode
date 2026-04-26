//
// Created by Milo on 4/26/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  bool containsCycle(vector<vector<char>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (!visited[i][j]) {
          if (findCycle(grid, visited, i, j, -1, -1)) {
            return true;
          }
        }
      }
    }
    return false;
  }
  bool findCycle(vector<vector<char>>& grid, vector<vector<bool>>& visited,
                 int row, int col, int last_row, int last_col) {
    visited[row][col] = true;
    char current_char = grid[row][col];

    int move_row[] = {-1, 1, 0, 0};
    int move_col[] = {0, 0, -1, 1};

    for (int i = 0; i < 4; i++) {
      int next_row = row + move_row[i];
      int next_col = col + move_col[i];

      if (next_row >= 0 && next_row < grid.size() && next_col >= 0 &&
          next_col < grid[0].size() &&
          grid[next_row][next_col] == current_char) {
        if (!visited[next_row][next_col]) {
          if (findCycle(grid, visited, next_row, next_col, row, col)) {
            return true;
          }
        } else if (next_row != last_row || next_col != last_col) {
          return true;
        }
      }
    }
    return false;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<vector<char>> grid = {{'a', 'a', 'a', 'a'},
                               {'a', 'b', 'b', 'a'},
                               {'a', 'b', 'b', 'a'},
                               {'a', 'a', 'a', 'a'}};
  bool result = sol.containsCycle(grid);
  bool result_expected = true;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  grid = {{'c', 'c', 'c', 'a'},
          {'c', 'd', 'c', 'c'},
          {'c', 'c', 'e', 'c'},
          {'f', 'c', 'c', 'c'}};
  result = sol.containsCycle(grid);
  result_expected = true;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  grid = {{'a', 'b', 'b'}, {'b', 'z', 'b'}, {'b', 'b', 'a'}};
  result = sol.containsCycle(grid);
  result_expected = false;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}