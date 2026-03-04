//
// Created by Milo on 3/4/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

class Solution {
 public:
  int numSpecial(vector<vector<int>>& mat) {
    int result = 0;
    vector<int> row_count(mat.size(), 0);
    vector<int> col_count(mat[0].size(), 0);
    for (int i = 0; i < mat.size(); i++) {
      for (int j = 0; j < mat[i].size(); j++) {
        if (mat[i][j] == 1) {
          row_count[i]++;
          col_count[j]++;
        }
      }
    }
    for (int i = 0; i < row_count.size(); i++) {
      for (int j = 0; j < col_count.size(); j++) {
        if (row_count[i] == 1 && col_count[j] == 1 && mat[i][j] == 1) {
          result++;
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
  vector<vector<int>> input = {{1, 0, 0}, {0, 0, 1}, {1, 0, 0}};
  int result = sol.numSpecial(input);
  int result_expected = 1;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  input = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
  result = sol.numSpecial(input);
  result_expected = 3;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}