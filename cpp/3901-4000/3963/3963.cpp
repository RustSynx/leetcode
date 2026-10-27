//
// Created by Milo on 10/27/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
 public:
  vector<string> createGrid(int m, int n) {
    vector<string> result(m);
    for (int i = 0; i < m; i++) {
      string s = "";
      for (int j = 0; j < n; j++) {
        if (i == 0) {
          s += '.';
        } else {
          if (j == n - 1) {
            s += '.';
          } else {
            s += '#';
          }
        }
      }
      result[i] = s;
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<string> result = sol.createGrid(2, 3);
  vector<string> result_expected = {"...", "##."};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.createGrid(3, 3);
  result_expected = {"...", "##.", "##."};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  result = sol.createGrid(1, 4);
  result_expected = {"...."};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}