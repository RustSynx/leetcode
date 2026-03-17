//
// Created by Milo on 3/17/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

class Solution {
 public:
  int largestSubmatrix(vector<vector<int>>& matrix) {
    for (int i = 0; i < matrix[0].size(); i++) {
      for (int j = 0; j < matrix.size(); j++) {
        if (j > 0 && matrix[j][i] != 0) {
          matrix[j][i] += matrix[j - 1][i];
        }
      }
    }
    int result = 0;
    for (int i = 0; i < matrix.size(); i++) {
      sort(matrix[i].begin(), matrix[i].end(), greater<int>());
      int sum = 0;
      for (int j = 0; j < matrix[i].size(); j++) {
        sum = (j + 1) * matrix[i][j];
        result = max(result, sum);
      }
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<vector<int>> input = {{0, 0, 1}, {1, 1, 1}, {1, 0, 1}};
  int result = sol.largestSubmatrix(input);
  int result_expected = 4;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  input = {{1, 0, 1, 0, 1}};
  result = sol.largestSubmatrix(input);
  result_expected = 3;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  input = {{1, 1, 0}, {1, 0, 1}};
  result = sol.largestSubmatrix(input);
  result_expected = 2;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}