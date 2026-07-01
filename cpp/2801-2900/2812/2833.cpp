//
// Created by Milo on 7/1/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maximumSafenessFactor(vector<vector<int>>& grid) {
    int n = grid.size();
    if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return 0;

    vector safeness(n, vector(n, -1));
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 1) {
          q.push({i, j});
          safeness[i][j] = 0;
        }
      }
    }

    int up_down[] = {-1, 1, 0, 0};
    int left_right[] = {0, 0, -1, 1};

    while (!q.empty()) {
      auto [row, col] = q.front();
      q.pop();

      for (int i = 0; i < 4; i++) {
        int new_row = row + up_down[i];
        int new_col = col + left_right[i];

        if (new_row >= 0 && new_row < n && new_col >= 0 &&
            new_col < n && safeness[new_row][new_col] == -1) {
          safeness[new_row][new_col] = safeness[row][col] + 1;
          q.push({new_row, new_col});
        }
      }
    }

    priority_queue<pair<int, pair<int, int>>> pq;
    vector visited(n, vector(n, false));

    pq.push({safeness[0][0], {0, 0}});
    visited[0][0] = true;

    while (!pq.empty()) {
      auto [current_safe, pos] = pq.top();
      auto [row, col] = pos;
      pq.pop();

      if (row == n - 1 && col == n - 1) {
        return current_safe;
      }

      for (int i = 0; i < 4; i++) {
        int new_row = row + up_down[i];
        int new_col = col + left_right[i];

        if (new_row >= 0 && new_row < n && new_col >= 0 &&
            new_col < n && !visited[new_row][new_col]) {
          visited[new_row][new_col] = true;
          int next_safe =
              min(current_safe, safeness[new_row][new_col]);
          pq.push({next_safe, {new_row, new_col}});
        }
      }
    }
    return 0;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<vector<int>> grid = {{1, 0, 0}, {0, 0, 0}, {0, 0, 1}};
  int result = sol.maximumSafenessFactor(grid);
  int result_expected = 0;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  grid = {{0, 0, 1}, {0, 0, 0}, {0, 0, 0}};
  result = sol.maximumSafenessFactor(grid);
  result_expected = 2;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  grid = {{0, 0, 0, 1}, {0, 0, 0, 0}, {0, 0, 0, 0}, {1, 0, 0, 0}};
  result = sol.maximumSafenessFactor(grid);
  result_expected = 2;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}