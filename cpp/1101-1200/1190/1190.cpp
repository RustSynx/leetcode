//
// Created by Milo on 9/27/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  string reverseParentheses(string s) {
    int r_pos;
    while ((r_pos = s.find(')')) != string::npos) {
      int l_pos = s.rfind('(', r_pos);
      string r_s = s.substr(l_pos + 1, r_pos - l_pos - 1);
      ranges::reverse(r_s);
      s.replace(l_pos, r_pos - l_pos + 1, r_s);
    }
    return s;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  string result = sol.reverseParentheses("(abcd)");
  string result_expected = "dcba";
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.reverseParentheses("(u(love)i)");
  result_expected = "iloveu";
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  result = sol.reverseParentheses("(ed(et(oc))el)");
  result_expected = "leetcode";
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}