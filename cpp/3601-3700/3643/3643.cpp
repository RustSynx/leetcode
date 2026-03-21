//
// Created by Milo on 3/21/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <ranges>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y,
                                       int k) {
    for (int i = x; i < x + k / 2; i++) {
      for (int j = y; j < y + k; j++) {
        int row_end = x + k - 1 - (i - x);
        swap(grid[i][j], grid[row_end][j]);
      }
    }
    return grid;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<vector<int>> input = {
      {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
  vector<vector<int>> result = sol.reverseSubmatrix(input, 1, 0, 3);
  vector<vector<int>> result_expected = {
      {1, 2, 3, 4}, {13, 14, 15, 8}, {9, 10, 11, 12}, {5, 6, 7, 16}};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  input = {{3, 4, 2, 3}, {2, 3, 4, 2}};
  result = sol.reverseSubmatrix(input, 0, 2, 2);
  result_expected = {{3, 4, 4, 2}, {2, 3, 2, 3}};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}