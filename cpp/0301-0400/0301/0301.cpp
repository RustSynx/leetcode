//
// Created by Milo on 10/7/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<string> removeInvalidParentheses(string s) {
    int left_p = 0;
    int right_p = 0;
    int open = 0;
    for (char c : s) {
      if (c == '(')
        left_p++;
      else if (c == ')') {
        if (left_p > 0) {
          left_p--;
        } else {
          right_p++;
        }
      }
    }
    unordered_set<string> valid_s;
    string curr = "";
    dfs(s, curr, 0, left_p, right_p, 0, valid_s);
    return vector<string>(valid_s.begin(), valid_s.end());
  }
  void dfs(string& s, string& curr, int idx, int left_p, int right_p, int open,
           unordered_set<string>& result) {
    if (s.length() == idx) {
      if (left_p == 0 && right_p == 0 && open == 0) result.insert(curr);
      return;
    }
    char c = s[idx];
    if (c == '(' && left_p > 0) {
      dfs(s, curr, idx + 1, left_p - 1, right_p, open, result);
    } else if (c == ')' && right_p > 0) {
      dfs(s, curr, idx + 1, left_p, right_p - 1, open, result);
    }
    curr.push_back(c);
    if (c == '(') {
      dfs(s, curr, idx + 1, left_p, right_p, open + 1, result);
    } else if (c == ')') {
      if (open > 0) {
        dfs(s, curr, idx + 1, left_p, right_p, open - 1, result);
      }
    } else {
      dfs(s, curr, idx + 1, left_p, right_p, open, result);
    }
    curr.pop_back();
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<string> result = sol.removeInvalidParentheses("()())()");
  vector<string> result_expected = {"()()()", "(())()"};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.removeInvalidParentheses("(a)())()");
  result_expected = {"(a)()()", "(a())()"};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  result = sol.removeInvalidParentheses(")(");
  result_expected = {""};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}