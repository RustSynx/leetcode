//
// Created by Milo on 10/3/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
 public:
  int longestValidParentheses(string s) {
    stack<int> idx;
    idx.push(-1);
    int result = 0;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == '(') {
        idx.push(i);
      } else {
        idx.pop();
        if (idx.empty()) {
          idx.push(i);
        } else {
          result = max(result, i - idx.top());
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
  int result = sol.longestValidParentheses("(()");
  int result_expected = 2;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.longestValidParentheses(")()())");
  result_expected = 4;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  result = sol.longestValidParentheses("");
  result_expected = 0;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}