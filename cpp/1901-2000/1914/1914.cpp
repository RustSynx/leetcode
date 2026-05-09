//
// Created by Milo on 5/9/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
    int m = static_cast<int>(grid.size());
    int n = static_cast<int>(grid[0].size());
    int start = 0;
    while ((m - start * 2) > 1 && (n - start * 2) > 1) {
      int step = k % ((m - start * 2) * 2 + (n - start * 2) * 2 - 4);
      for (int i = 0; i < step; i++) {
        for (int j = 0; j < m - (start * 2) - 1; j++) {
          swap(grid[start + j][n - start - 1], grid[start + j + 1][n - start - 1]);
        }
        for (int j = 0; j < n - (start * 2) - 1; j++) {
          swap(grid[m - start - 1][n - j - start - 1], grid[m - start - 1][n - j - start - 2]);
        }
        for (int j = 0; j < m - (start * 2) - 1; j++) {
          swap(grid[m - j - start - 1][start], grid[m - j - start - 2][start]);
        }
        for (int j = 0; j < n - (start * 2) - 2; j++) {
          swap(grid[start][j + start], grid[start][j + start + 1]);
        }
      }
      start++;
    }
    return grid;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<vector<int>> grid = {{40, 10}, {30, 20}};
  vector<vector<int>> result = sol.rotateGrid(grid, 1);
  vector<vector<int>> result_expected = {{10, 20}, {40, 30}};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  grid = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
  result = sol.rotateGrid(grid, 2);
  result_expected = {
      {3, 4, 8, 12}, {2, 11, 10, 16}, {1, 7, 6, 15}, {5, 9, 13, 14}};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}