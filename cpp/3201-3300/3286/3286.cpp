//
// Created by Milo on 7/2/26.
//
#include <algorithm>
#include <cassert>
#include <deque>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

class Solution {
 public:
  int m, n;
  bool findSafeWalk(vector<vector<int>>& grid, int health) {
    m = grid.size();
    n = grid[0].size();
    vector max_health(m, vector(n, -1));
    deque<tuple<int, int, int>> curr_state;
    curr_state.push_back({0, 0, health - grid[0][0]});
    while (!curr_state.empty()) {
      auto [row, col, h] = curr_state.front();
      curr_state.pop_front();
      if (row == m - 1 && col == n - 1) return true;
      if (max_health[row][col] >= h) {
        continue;
      }
      max_health[row][col] = h;
      int up_down[] = {0, 0, 1, -1};
      int left_right[] = {1, -1, 0, 0};
      for (int i = 0; i < 4; i++) {
        int new_row = row + up_down[i];
        int new_col = col + left_right[i];
        if (new_row >= 0 && new_row < m && new_col >= 0 && new_col < n) {
          int cost = grid[new_row][new_col];
          int next_h = h - cost;
          if (next_h > 0) {
            if (cost == 0) {
              curr_state.push_front({new_row, new_col, next_h});
            } else {
              curr_state.push_back({new_row, new_col, next_h});
            }
          }
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
  vector<vector<int>> grid = {
      {0, 1, 0, 0, 0}, {0, 1, 0, 1, 0}, {0, 0, 0, 1, 0}};
  bool result = sol.findSafeWalk(grid, 1);
  bool result_expected = true;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  grid = {{0, 1, 1, 0, 0, 0},
          {1, 0, 1, 0, 0, 0},
          {0, 1, 1, 1, 0, 1},
          {0, 0, 1, 0, 1, 0}};
  result = sol.findSafeWalk(grid, 3);
  result_expected = false;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  grid = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
  result = sol.findSafeWalk(grid, 5);
  result_expected = true;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}