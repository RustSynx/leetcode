//
// Created by Milo on 7/5/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> pathsWithMaxScore(vector<string>& board) {
    int m = board.size();
    int n = board[0].size();
    int mod = 1e9 + 7;
    vector max_sum(m, vector<int>(n));
    vector count_path(m, vector<int>(n));
    int row_idx[] = {0, 1, 1};
    int col_idx[] = {1, 0, 1};
    for (int i = m - 1; i >= 0; i--) {
      for (int j = n - 1; j >= 0; j--) {
        char curr_char = board[i][j];
        switch (curr_char) {
          case 'X':
            max_sum[i][j] = 0;
            count_path[i][j] = 0;
            continue;
          case 'S':
            max_sum[i][j] = 0;
            count_path[i][j] = 1;
            continue;
        }
        long long curr_num = curr_char == 'E' ? 0 : curr_char - '0';
        long long curr_max = curr_num;
        for (int k = 0; k < 3; k++) {
          int prev_row = i + row_idx[k];
          int prev_col = j + col_idx[k];
          if (prev_row < m && prev_col < n && count_path[prev_row][prev_col] != 0) {
            curr_max = max(curr_max, curr_num + max_sum[prev_row][prev_col]);
          }
        }
        max_sum[i][j] = curr_max;
        for (int k = 0; k < 3; k++) {
          int prev_row = i + row_idx[k];
          int prev_col = j + col_idx[k];
          if (prev_row < m && prev_col < n && curr_max == curr_num + max_sum[prev_row][prev_col]) {
            count_path[i][j] = (count_path[i][j] + count_path[prev_row][prev_col]) % mod;
          }
        }
        if (count_path[i][j] == 0) max_sum[i][j] = 0;
      }
    }
    return {max_sum[0][0], count_path[0][0]};
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<string> board = {"E23", "2X2", "12S"};
  vector<int> result = sol.pathsWithMaxScore(board);
  vector<int> result_expected = {7, 1};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  board = {"E12", "1X1", "21S"};
  result = sol.pathsWithMaxScore(board);
  result_expected = {4, 2};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  board = {"E11", "XXX", "11S"};
  result = sol.pathsWithMaxScore(board);
  result_expected = {0, 0};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}