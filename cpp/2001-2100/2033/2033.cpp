//
// Created by Milo on 4/28/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int minOperations(vector<vector<int>>& grid, int x) {
    int m = static_cast<int>(grid.size());
    int n = static_cast<int>(grid[0].size());
    vector<int> all_number(m * n, 0);
    int idx = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        all_number[idx] = grid[i][j];
        idx++;
      }
    }
    ranges::sort(all_number);
    int target = all_number[m * n / 2];
    int result = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (abs(target - grid[i][j]) % x != 0) return -1;
        result += (abs(target - grid[i][j])) / x;
      }
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<vector<int>> grid = {{2, 4}, {6, 8}};
  int result = sol.minOperations(grid, 2);
  int result_expected = 4;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  grid = {{1, 5}, {2, 3}};
  result = sol.minOperations(grid, 1);
  result_expected = 5;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  grid = {{1, 2}, {3, 4}};
  result = sol.minOperations(grid, 2);
  result_expected = -1;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}