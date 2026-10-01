//
// Created by Milo on 10/1/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
  bool isValid(string s) {
    stack<char> stack_c;
    for (char c: s) {
      if (c == '(' || c == '{' || c == '[') {
        stack_c.push(c);
      } else {
        if (stack_c.empty()) return false;
        if (abs(c - stack_c.top()) <= 2) {
          stack_c.pop();
        } else {
          return false;
        }
      }
    }
    return stack_c.empty();
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  bool result = sol.isValid("()");
  bool result_expected = true;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.isValid("()[]{}");
  result_expected = true;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  result = sol.isValid("(]");
  result_expected = false;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 4
  cout << "Test Case 4: " << endl;
  result = sol.isValid("([])");
  result_expected = true;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 5
  cout << "Test Case 5: " << endl;
  result = sol.isValid("([)]");
  result_expected = false;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}