//
// Created by Milo on 11/8/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int countServers(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<int> r_cnt(m);
    vector<int> c_cnt(n);
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 0) continue;
        r_cnt[i]++;
        c_cnt[j]++;
      }
    }
    int result = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 0) continue;
        if (r_cnt[i] > 1 || c_cnt[j] > 1) result++;
      }
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<vector<int>> grid = {{1, 0}, {0, 1}};
  int result = sol.countServers(grid);
  int result_expected = 0;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  grid = {{1, 0}, {1, 1}};
  result = sol.countServers(grid);
  result_expected = 3;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  grid = {{1, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
  result = sol.countServers(grid);
  result_expected = 4;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}