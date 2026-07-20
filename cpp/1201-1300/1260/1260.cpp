//
// Created by Milo on 7/20/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> result(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        int new_idx = (i * n + j + k) % (m * n);
        int new_row = new_idx / n;
        int new_col = new_idx % n;
        result[new_row][new_col] = grid[i][j];
      }
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<vector<int>> grid = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  vector<vector<int>> result = sol.shiftGrid(grid, 1);
  vector<vector<int>> result_expected = {{9, 1, 2}, {3, 4, 5}, {6, 7, 8}};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  grid = {{3, 8, 1, 9}, {19, 7, 2, 5}, {4, 6, 11, 10}, {12, 0, 21, 13}};
  result = sol.shiftGrid(grid, 4);
  result_expected = {
      {12, 0, 21, 13}, {3, 8, 1, 9}, {19, 7, 2, 5}, {4, 6, 11, 10}};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  grid = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  result = sol.shiftGrid(grid, 9);
  result_expected = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}