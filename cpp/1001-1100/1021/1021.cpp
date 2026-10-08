//
// Created by Milo on 10/8/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  string removeOuterParentheses(string s) {
    int open = 0;
    string result;
    for (char c : s) {
      if (c == '(') {
        open++;
        if (open > 1) result += c;
      } else {
        open--;
        if (open > 0) result += c;
      }
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  string result = sol.removeOuterParentheses("(()())(())");
  string result_expected = "()()()";
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.removeOuterParentheses("(()())(())(()(()))");
  result_expected = "()()()()(())";
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  result = sol.removeOuterParentheses("()()");
  result_expected = "";
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;
  return 0;
}