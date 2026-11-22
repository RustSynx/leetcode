//
// Created by Milo on 11/22/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool checkString(string s) {
      return is_sorted(s.begin(), s.end());
    }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  bool result = sol.checkString("aaabbb");
  bool result_expected = true;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.checkString("abab");
  result_expected = false;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  result = sol.checkString("bbb");
  result_expected = true;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}