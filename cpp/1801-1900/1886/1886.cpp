//
// Created by Milo on 3/22/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
    vector<bool> result(4, true);
    int n = static_cast<int>(mat.size());
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (mat[i][j] != target[i][j]) {
          result[0] = false;
        }
        if (mat[i][j] != target[j][n - 1 - i]) {
          result[1] = false;
        }
        if (mat[i][j] != target[n - 1 - i][n - 1 - j]) {
          result[2] = false;
        }
        if (mat[i][j] != target[n - 1 - j][i]) {
          result[3] = false;
        }
        if (!result[0] && !result[1] && !result[2] && !result[3]) return false;
      }
    }
    return result[0] || result[1] || result[2] || result[3];
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<vector<int>> input = {{0, 1},{1, 0}};
  vector<vector<int>> target = {{1, 0},{0, 1}};
  bool result = sol.findRotation(input, target);
  bool result_expected = true;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  input = {{0, 1},{1, 1}};
  target = {{1, 0},{0, 1}};
  result = sol.findRotation(input, target);
  result_expected = false;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  input = {{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};
  target = {{1, 1, 1}, {0, 1, 0}, {0, 0, 0}};
  result = sol.findRotation(input, target);
  result_expected = true;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}