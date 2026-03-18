//
// Created by Milo on 3/18/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <deque>
#include <set>

using namespace std;

class Solution {
public:
  int countSubmatrices(vector<vector<int>>& grid, int k) {
    int result = 0;
    for (int i = 0; i < grid.size(); i++) {
      int sum = 0;
      for (int j = 0; j < grid[i].size(); j++) {
        if (i > 0) {
          grid[i][j] = grid[i-1][j] + grid[i][j];
        }
        sum += grid[i][j];
        if (sum <= k) {
          result++;
        } else {
          break;
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
  vector<vector<int>> input = {{7,6,3},{6,6,1}};
  int result = sol.countSubmatrices(input, 18);
  int result_expected = 4;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  input = {{7,2,9},{1,5,0},{2,6,6}};
  result = sol.countSubmatrices(input, 20);
  result_expected = 6;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}