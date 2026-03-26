//
// Created by Milo on 3/26/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        long long total_sum = 0;
        vector<long long> row_sum(m, 0);
        vector<long long> col_sum(n, 0);

        unordered_map<long long, int> min_r, max_r, min_c, max_c;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                long long val = grid[i][j];
                total_sum += val;
                row_sum[i] += val;
                col_sum[j] += val;

                if (min_r.find(val) == min_r.end()) {
                    min_r[val] = i; max_r[val] = i;
                    min_c[val] = j; max_c[val] = j;
                } else {
                    min_r[val] = min(min_r[val], i);
                    max_r[val] = max(max_r[val], i);
                    min_c[val] = min(min_c[val], j);
                    max_c[val] = max(max_c[val], j);
                }
            }
        }

        long long top_sum = 0;
        for (int i = 0; i < m - 1; i++) {
            top_sum += row_sum[i];
            long long bot_sum = total_sum - top_sum;

            if (top_sum == bot_sum) return true;

            long long target_top = top_sum - bot_sum;
            if (min_r.count(target_top)) {
                if (i == 0 || n == 1) {
                    if (target_top == grid[0][0] || target_top == grid[i][n - 1]) return true;
                } else {
                    if (min_r[target_top] <= i) return true;
                }
            }

            long long target_bot = bot_sum - top_sum;
            if (max_r.count(target_bot)) {
                if (i == m - 2 || n == 1) {
                    if (target_bot == grid[i + 1][0] || target_bot == grid[m - 1][n - 1]) return true;
                } else {
                    if (max_r[target_bot] > i) return true;
                }
            }
        }

        long long left_sum = 0;
        for (int j = 0; j < n - 1; j++) {
            left_sum += col_sum[j];
            long long right_sum = total_sum - left_sum;

            if (left_sum == right_sum) return true;

            long long target_left = left_sum - right_sum;
            if (min_c.count(target_left)) {
                if (j == 0 || m == 1) {
                    if (target_left == grid[0][0] || target_left == grid[m - 1][j]) return true;
                } else {
                    if (min_c[target_left] <= j) return true;
                }
            }

            long long target_right = right_sum - left_sum;
            if (max_c.count(target_right)) {
                if (j == n - 2 || m == 1) {
                    if (target_right == grid[0][j + 1] || target_right == grid[m - 1][n - 1]) return true;
                } else {
                    if (max_c[target_right] > j) return true;
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
  vector<vector<int>> input = {{1, 4}, {2, 3}};
  bool result = sol.canPartitionGrid(input);
  bool result_expected = true;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  input = {{1, 2}, {3, 4}};
  result = sol.canPartitionGrid(input);
  result_expected = true;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  input = {{1, 2, 4}, {2, 3, 5}};
  result = sol.canPartitionGrid(input);
  result_expected = false;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 4
  cout << "Test Case 3: " << endl;
  input = {{4, 1, 8}, {3, 2, 6}};
  result = sol.canPartitionGrid(input);
  result_expected = false;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}