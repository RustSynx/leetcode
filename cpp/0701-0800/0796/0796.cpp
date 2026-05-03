//
// Created by Milo on 2/14/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

class Solution {
public:
  bool rotateString(string s, string goal) {
    if (s.length() != goal.length()) return false;
    string goal_candidate = s + s;
    return goal_candidate.find(goal) != string::npos;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  bool result = sol.rotateString("abcde", "cdeab");
  bool result_expected = true;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.rotateString("abcde", "abced");
  result_expected = false;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}