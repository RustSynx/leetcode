//
// Created by Milo on 3/1/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int minimumOR(vector<vector<int>>& grid) {
    int answer = (1 << 17) - 1;

    for (int i = 16; i >= 0; --i) {
      int target = answer ^ (1 << i);

      if (possible_in_row(grid, target)) {
        answer = target;
      }
    }

    return answer;
  }
  bool possible_in_row(const vector<vector<int>>& grid, int target) {
    for (const auto& row : grid) {
      bool possible = false;
      for (int val : row) {
        if ((val | target) == target) {
          possible = true;
          break;
        }
      }
      if (!possible) return false;
    }
    return true;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<vector<int>> input = {{1, 5}, {2, 4}};
  int result = sol.minimumOR(input);
  int result_expected = 3;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  input = {{3, 5}, {6, 4}};
  result = sol.minimumOR(input);
  result_expected = 5;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}