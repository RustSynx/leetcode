//
// Created by Milo on 9/20/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  int reverseDegree(string s) {
    int n = s.length();
    int result = 0;
    for (int i = 0; i < n; i++) {
      int idx = s[i] - 'a';
      result += (26 - idx) * (i + 1);
    }
    return result;
  }
};

int main() {
  Solution sol;
  // Test Case 1
  cout << "Test Case 1: " << endl;
  int result = sol.reverseDegree("abc");
  int result_expected = 148;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.reverseDegree("zaza");
  result_expected = 160;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}