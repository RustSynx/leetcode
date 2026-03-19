//
// Created by Milo on 3/19/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int numberOfSubmatrices(vector<vector<char>>& grid) {
    int result = 0;
    int col_size = static_cast<int>(grid.size());
    int row_size = static_cast<int>(grid[0].size());
    vector<vector<pair<int, int>>> acc_sum(
        col_size + 1, vector<pair<int, int>>(row_size + 1, {0, 0}));
    for (int i = 1; i <= col_size; i++) {
      for (int j = 1; j <= row_size; j++) {
        int current_num = check_char(grid[i - 1][j - 1]);
        acc_sum[i][j].first = current_num + acc_sum[i - 1][j].first +
                              acc_sum[i][j - 1].first -
                              acc_sum[i - 1][j - 1].first;
        acc_sum[i][j].second =
            acc_sum[i - 1][j].second + acc_sum[i][j - 1].second +
            (current_num == 1 ? 1 : 0) - acc_sum[i - 1][j - 1].second;
        if (acc_sum[i][j].first == 0 && acc_sum[i][j].second > 0) {
          result++;
        }
      }
    }
    return result;
  }
  int check_char(char c) {
    switch (c) {
      case 'X':
        return 1;
      case 'Y':
        return -1;
      default:
        return 0;
    }
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<vector<char>> input = {{'X', 'Y', '.'}, {'Y', '.', '.'}};
  int result = sol.numberOfSubmatrices(input);
  int result_expected = 3;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  input = {{'X', 'X'}, {'X', 'Y'}};
  result = sol.numberOfSubmatrices(input);
  result_expected = 0;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  input = {{'.', '.'}, {'.', '.'}};
  result = sol.numberOfSubmatrices(input);
  result_expected = 0;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}