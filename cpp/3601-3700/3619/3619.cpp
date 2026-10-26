//
// Created by Milo on 10/26/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
 public:
  int m;
  int n;
  int countIslands(vector<vector<int>>& grid, int k) {
    m = grid.size();
    n = grid[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    queue<pair<int, int>> q;
    int result = 0;
    int r[] = {1, -1, 0, 0};
    int c[] = {0, 0, 1, -1};
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] != 0 && !visited[i][j]) {
          q.push({i, j});
          visited[i][j] = true;
          long long sum = 0;
          while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();
            sum += grid[row][col];
            for (int d = 0; d < 4; d++) {
              int nr = row + r[d];
              int nc = col + c[d];
              if (nr >= 0 && nc >= 0 && nr < m && nc < n && grid[nr][nc] != 0 &&
                  !visited[nr][nc]) {
                visited[nr][nc] = true;
                q.push({nr, nc});
              }
            }
          }
          if (sum % k == 0 && sum != 0) result++;
        }
      }
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<vector<int>> grid = {{0, 2, 1, 0, 0},
                              {0, 5, 0, 0, 5},
                              {0, 0, 1, 0, 0},
                              {0, 1, 4, 7, 0},
                              {0, 2, 0, 0, 8}};
  int result = sol.countIslands(grid, 5);
  int result_expected = 2;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  grid = {{3, 0, 3, 0}, {0, 3, 0, 3}, {3, 0, 3, 0}};
  result = sol.countIslands(grid, 3);
  result_expected = 6;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}