//
// Created by Milo on 6/20/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxBuilding(int n, vector<vector<int>>& restrictions) {
    restrictions.push_back({1, 0});

    sort(restrictions.begin(), restrictions.end());

    int m = restrictions.size();

    for (int i = 1; i < m; i++) {
      int dist = restrictions[i][0] - restrictions[i - 1][0];
      restrictions[i][1] =
          min(restrictions[i][1], restrictions[i - 1][1] + dist);
    }

    for (int i = m - 2; i >= 0; i--) {
      int dist = restrictions[i + 1][0] - restrictions[i][0];
      restrictions[i][1] =
          min(restrictions[i][1], restrictions[i + 1][1] + dist);
    }

    int result = 0;
    for (int i = 1; i < m; i++) {
      int id1 = restrictions[i - 1][0];
      int h1 = restrictions[i - 1][1];
      int id2 = restrictions[i][0];
      int h2 = restrictions[i][1];

      int max_height = (h1 + h2 + (id2 - id1)) / 2;
      result = max(result, max_height);
    }

    result = max(result, restrictions[m - 1][1] + (n - restrictions[m - 1][0]));

    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<vector<int>> restrictions = {{2, 1}, {4, 1}};
  int result = sol.maxBuilding(5, restrictions);
  int result_expected = 2;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  restrictions = {};
  result = sol.maxBuilding(6, restrictions);
  result_expected = 5;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  restrictions = {{5, 3}, {2, 5}, {7, 4}, {10, 3}};
  result = sol.maxBuilding(10, restrictions);
  result_expected = 5;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}