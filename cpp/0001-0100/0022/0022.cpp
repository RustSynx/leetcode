//
// Created by Milo on 10/2/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<string> generateParenthesis(int n) {
    vector<string> result;
    string s;
    s.reserve(n * 2);
    dfs(result, s, 0, 0, n);
    return result;
  }
  void dfs(vector<string>& result, string& s, int open, int close, int n) {
    if (n * 2 == s.length()) {
      result.push_back(s);
      return;
    }
    if (open < n) {
      s.push_back('(');
      dfs(result, s, open + 1, close, n);
      s.pop_back();
    }
    if (close < open) {
      s.push_back(')');
      dfs(result, s, open, close + 1, n);
      s.pop_back();
    }
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<string> result = sol.generateParenthesis(3);
  vector<string> result_expected = {"((()))", "(()())", "(())()", "()(())",
                                    "()()()"};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.generateParenthesis(1);
  result_expected = {"()"};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}