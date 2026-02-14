//
// Created by Milo on 2/14/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  double champagneTower(int poured, int query_row, int query_glass) {
    vector<vector<double>> shampagne(query_row + 1, vector<double>(query_row + 1, 0.0));
    shampagne[0][0] = poured;
    for (int i = 0; i < query_row; i++) {
      for (int j = 0; j <= i; j++) {
        if (shampagne[i][j] > 1.0) {
          shampagne[i][j] -= 1.0;
          shampagne[i + 1][j] += shampagne[i][j] / 2.0;
          shampagne[i + 1][j + 1] += shampagne[i][j] / 2.0;
        }
      }
    }
    return min(1.0, shampagne[query_row][query_glass]);
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  double result = sol.champagneTower(1, 1, 1);
  double result_expected = 0.0;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.champagneTower(2,1,1);
  result_expected = 0.5;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  result = sol.champagneTower(100000009, 33, 17);
  result_expected = 1.0;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}