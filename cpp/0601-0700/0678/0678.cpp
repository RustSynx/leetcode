//
// Created by Milo on 10/4/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  bool checkValidString(string s) {
    int min_open = 0;
    int max_open = 0;
    for (char c : s) {
      if (c == '(') {
        min_open++;
        max_open++;
      }
      if (c == ')') {
        min_open--;
        max_open--;
      }
      if (c == '*') {
        min_open--;
        max_open++;
      }
      if (max_open < 0) return false;
      if (min_open < 0) min_open = 0;
    }
    return min_open == 0;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  bool result = sol.checkValidString("()");
  bool result_expected = true;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.checkValidString("(*)");
  result_expected = true;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  result = sol.checkValidString("(*))");
  result_expected = true;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 4
  cout << "Test Case 4: " << endl;
  result = sol.checkValidString("(");
  result_expected = false;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}