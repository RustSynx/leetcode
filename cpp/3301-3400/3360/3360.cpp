//
// Created by Milo on 11/26/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

class Solution {
 public:
  bool canAliceWin(int n) {
    int move_s = 10;
    while (n >= move_s) {
      n -= move_s;
      move_s--;
    }
    return move_s % 2 != 0;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  bool result = sol.canAliceWin(12);
  bool result_expected = true;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.canAliceWin(1);
  result_expected = false;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}