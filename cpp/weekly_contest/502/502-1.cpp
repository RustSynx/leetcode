//
// Created by Milo on 5/17/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

class Solution {
public:
  bool isAdjacentDiffAtMostTwo(string s) {
    int n = static_cast<int>(s.length());
    for (int i = 0; i < n - 1; i++) {
      if (abs(s[i] - s[i + 1]) > 2) return false;
    }
    return true;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  bool result = sol.isAdjacentDiffAtMostTwo("132");
  bool result_expected = true;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.isAdjacentDiffAtMostTwo("129");
  result_expected = false;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}