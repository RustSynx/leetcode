//
// Created by Milo on 3/21/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
  vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1, 0));

    for (int i = 0; i <= m - k; i++) {
      for (int j = 0; j <= n - k; j++) {
        vector<int> values;
        values.reserve(k * k);

        for (int a = 0; a < k; a++) {
          for (int b = 0; b < k; b++) {
            values.push_back(grid[i + a][j + b]);
          }
        }

        sort(values.begin(), values.end());

        int min_diff = INT_MAX;
        for (int a = 1; a < values.size(); a++) {
          if (values[a] != values[a - 1]) {
            min_diff = min(min_diff, values[a] - values[a - 1]);
          }
        }

        ans[i][j] = (min_diff == INT_MAX) ? 0 : min_diff;
      }
    }
    return ans;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<vector<int>> input = {{1, 8}, {3, -2}};
  vector<vector<int>> result = sol.minAbsDiff(input, 2);
  vector<vector<int>> result_expected = {{2}};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  input = {{3, -1}};
  result = sol.minAbsDiff(input, 1);
  result_expected = {{0, 0}};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  input = {{1, -2, 3}, {2, 3, 5}};
  result = sol.minAbsDiff(input, 2);
  result_expected = {{1, 2}};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}