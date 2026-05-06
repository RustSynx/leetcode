//
// Created by Milo on 5/6/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
    int m = static_cast<int>(boxGrid.size());
    int n = static_cast<int>(boxGrid[0].size());
    vector<vector<char>> rotated_vec(n, vector<char>(m));
    for (int i = 0; i < m; i++) {
      int start = n - 1;
      int end = n - 1;
      while (start >= 0) {
        if (boxGrid[i][start] == '*') {
          start--;
          end = start;
        } else if (boxGrid[i][start] == '.') {
          start--;
        } else if (boxGrid[i][start] == '#' && start != end) {
          char temp = boxGrid[i][start];
          boxGrid[i][start] = boxGrid[i][end];
          boxGrid[i][end] = temp;
          start--;
          end--;
        } else {
          start--;
          end--;
        }
      }
    }
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        rotated_vec[j][i] = boxGrid[m - i - 1][j];
      }
    }
    return rotated_vec;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<vector<char>> boxGrid = {{'#', '.', '#'}};
  vector<vector<char>> result = sol.rotateTheBox(boxGrid);
  vector<vector<char>> result_expected = {{'.'}, {'#'}, {'#'}};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  boxGrid = {{'#', '.', '*', '.'}, {'#', '#', '*', '.'}};
  result = sol.rotateTheBox(boxGrid);
  result_expected = {{'#', '.'}, {'#', '#'}, {'*', '*'}, {'.', '.'}};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  boxGrid = {{'#', '#', '*', '.', '*', '.'},
             {'#', '#', '#', '*', '.', '.'},
             {'#', '#', '#', '.', '#', '.'}};
  result = sol.rotateTheBox(boxGrid);
  result_expected = {{'.', '#', '#'}, {'.', '#', '#'}, {'#', '#', '*'},
                     {'#', '*', '.'}, {'#', '.', '*'}, {'#', '.', '.'}};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}