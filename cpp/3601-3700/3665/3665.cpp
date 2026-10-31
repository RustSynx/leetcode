//
// Created by Milo on 10/31/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int m, n;
  int mod = 1e9 + 7;
  int uniquePaths(vector<vector<int>>& grid) {
    m = grid.size();
    n = grid[0].size();
    vector<vector<vector<int>>> visited(m, vector<vector<int>>(n, vector<int>(2, -1)));
    return dfs(grid, visited, 0, 0, 0);
  }
  long long dfs(vector<vector<int>>& grid, vector<vector<vector<int>>>& visited, int r, int c, int dir) {
    if (m - 1 < r || n - 1 < c) return 0;
    if (m - 1 == r && n - 1 == c) return 1;
    if (visited[r][c][dir] != -1) {
      return visited[r][c][dir];
    }
    long long sum = 0;
    if (grid[r][c] == 1) {
      if (dir == 0) {
        sum = (sum + dfs(grid, visited, r + 1, c, 1)) % mod;
      } else {
        sum = (sum + dfs(grid, visited, r, c + 1, 0)) % mod;
      }
    } else {
      sum = (sum + dfs(grid, visited, r + 1, c, 1)) % mod;
      sum = (sum + dfs(grid, visited, r, c + 1, 0)) % mod;
    }
    return visited[r][c][dir] = sum;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<vector<int>> grid = {{0, 1, 0}, {0, 0, 1}, {1, 0, 0}};
  int result = sol.uniquePaths(grid);
  int result_expected = 5;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  grid = {{0, 0}, {0, 0}};
  result = sol.uniquePaths(grid);
  result_expected = 2;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  grid = {{0, 1, 1}, {1, 1, 0}};
  result = sol.uniquePaths(grid);
  result_expected = 1;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}