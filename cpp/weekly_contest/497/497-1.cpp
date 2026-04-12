//
// Created by Milo on 4/12/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> findDegrees(vector<vector<int>>& matrix) {
    int n = static_cast<int>(matrix.size());
    vector<int> result(n, 0);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (matrix[i][j] == 1) {
          result[i]++;
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
  vector<vector<int>> matrix = {{0, 1, 1}, {1, 0, 1}, {1, 1, 0}};
  vector<int> result = sol.findDegrees(matrix);
  vector<int> result_expected = {2, 2, 2};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  matrix = {{0, 1, 0}, {1, 0, 0}, {0, 0, 0}};
  result = sol.findDegrees(matrix);
  result_expected = {1, 1, 0};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  matrix = {{0}};
  result = sol.findDegrees(matrix);
  result_expected = {0};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}