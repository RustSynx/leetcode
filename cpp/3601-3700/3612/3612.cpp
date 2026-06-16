//
// Created by Milo on 6/16/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

class Solution {
 public:
  string processStr(string s) {
    string result;
    for (char c : s) {
      switch (c) {
        case '*':
          if (!result.empty()) result.pop_back();
          break;
        case '#':
          result += result;
          break;
        case '%':
          ranges::reverse(result);
          break;
        default:
          result += c;
      }
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  string s = "a#b%*";
  string result = sol.processStr(s);
  string result_expected = "ba";
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  s = "z*#";
  result = sol.processStr(s);
  result_expected = "";
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}