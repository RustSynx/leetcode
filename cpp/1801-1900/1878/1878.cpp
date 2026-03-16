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
    vector<vector<int>> left_acc_sum(grid.size(), vector<int>(grid[0].size(), 0));
    vector<vector<int>> right_acc_sum(grid.size(), vector<int>(grid[0].size(), 0));
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        sum_set.insert(grid[i][j]);
        left_acc_sum[i][j] = (i-1 >=0 && j-1 >= 0) ? left_acc_sum[i-1][j-1] + grid[i][j] : grid[i][j];
        right_acc_sum[i][j] = (i-1 >= 0 && j+1 < grid[0].size()) ? right_acc_sum[i-1][j+1] + grid[i][j] : grid[i][j];
      }
    }
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        int radius = 1;
        while (radius < grid.size()) {
          int top = i - radius;
          int bottom = i + radius;
          int left = j - radius;
          int right = j + radius;
          if (top < 0) break;
          if (bottom > grid.size() - 1) break;
          if (left < 0) break;
          if (right > grid[0].size() - 1) break;
          int sum = 0;
          sum += left_acc_sum[i][right] - (top-1 >= 0 && j-1 >= 0 ? left_acc_sum[top-1][j-1] : 0);
          sum += left_acc_sum[bottom][j] - (i-1 >= 0 && left-1 >= 0 ? left_acc_sum[i-1][left-1] : 0);
          sum += right_acc_sum[i][left] - (top-1 >= 0 && j+1 < grid[0].size() ? right_acc_sum[top-1][j+1] : 0);
          sum += right_acc_sum[bottom][j] - (i-1 >= 0 && right+1 < grid[0].size() ? right_acc_sum[i-1][right+1] : 0);
          sum -= grid[top][j] + grid[bottom][j] + grid[i][left] + grid[i][right];
          sum_set.insert(sum);
          radius++;
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
  vector<vector<int>> input = {{3,4,5,1,3},{3,3,4,2,3},{20,30,200,40,10},{1,5,5,4,1},{4,3,2,2,5}};
  vector<int> result = sol.getBiggestThree(input);
  vector<int> result_expected = {228,216,211};
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
  input = {{1,2,3},{4,5,6},{7,8,9}};
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
  input = {{7,7,7}};
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