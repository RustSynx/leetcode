//
// Created by Milo on 3/16/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> getBiggestThree(vector<vector<int>>& grid) {
    set<int, greater<int>> sum_set;
    int m = static_cast<int>(grid.size());
    int n = static_cast<int>(grid[0].size());
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        sum_set.insert(grid[i][j]);
        for (int radius = 1; radius < 25; radius++) {
          if (i - radius < 0 || j - radius < 0 || i + radius >= m ||
              j + radius >= n)
            break;
          int sum = 0;
          int x_step[] = {1, 1, -1, -1};
          int y_step[] = {-1, 1, 1, -1};
          int x = j - radius;
          int y = i;
          for (int k = 0; k < 4; k++) {
            for (int l = 0; l < radius; l++) {
              sum += grid[y][x];
              x += x_step[k];
              y += y_step[k];
            }
          }
          sum_set.insert(sum);
        }
      }
    }
    vector<int> result;
    for (int num : sum_set) {
      result.push_back(num);
      if (result.size() == 3) break;
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<vector<int>> input = {{3, 4, 5, 1, 3},
                               {3, 3, 4, 2, 3},
                               {20, 30, 200, 40, 10},
                               {1, 5, 5, 4, 1},
                               {4, 3, 2, 2, 5}};
  vector<int> result = sol.getBiggestThree(input);
  vector<int> result_expected = {228, 216, 211};
  cout << "result : ";
  for (int num : result) {
    cout << num << " ";
  }
  cout << endl;
  cout << "result_expected : ";
  for (int num : result_expected) {
    cout << num << " ";
  }
  cout << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  input = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  result = sol.getBiggestThree(input);
  result_expected = {20, 9, 8};
  cout << "result : ";
  for (int num : result) {
    cout << num << " ";
  }
  cout << endl;
  cout << "result_expected : ";
  for (int num : result_expected) {
    cout << num << " ";
  }
  cout << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  input = {{7, 7, 7}};
  result = sol.getBiggestThree(input);
  result_expected = {7};
  cout << "result : ";
  for (int num : result) {
    cout << num << " ";
  }
  cout << endl;
  cout << "result_expected : ";
  for (int num : result_expected) {
    cout << num << " ";
  }
  cout << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}