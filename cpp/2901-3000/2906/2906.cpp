//
// Created by Milo on 3/24/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <deque>
#include <set>

using namespace std;

class Solution {
public:
  vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
    int mod = 12345;
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> result(n, vector<int>(m, 0));
    long long prefix_product = 1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        result[i][j] = prefix_product;
        prefix_product = prefix_product * grid[i][j] % mod;
      }
    }
    prefix_product = 1;
    for (int i = n - 1; i >= 0; i--) {
      for (int j = m - 1; j >= 0; j--) {
        result[i][j] = result[i][j] * prefix_product % mod;
        prefix_product = prefix_product * grid[i][j] % mod;
      }
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<vector<int>> input = {{1,2},{3,4}};
  vector<vector<int>> result = sol.constructProductMatrix(input);
  vector<vector<int>> result_expected = {{24,12},{8,6}};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  input = {{12345},{2},{1}};
  result = sol.constructProductMatrix(input);
  result_expected = {{2}, {0}, {0}};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}