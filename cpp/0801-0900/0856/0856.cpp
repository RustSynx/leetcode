//
// Created by Milo on 10/5/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  int scoreOfParentheses(string s) {
    int depth = 0;
    int result = 0;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == '(') {
        depth++;
      }
      if (s[i] == ')') {
        depth--;
        if (s[i - 1] == '(') {
          result += 1 << depth;
        }
      }
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  int result = sol.scoreOfParentheses("()");
  int result_expected = 1;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.scoreOfParentheses("(())");
  result_expected = 2;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  result = sol.scoreOfParentheses("()()");
  result_expected = 2;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}