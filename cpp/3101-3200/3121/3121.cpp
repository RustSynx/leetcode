//
// Created by Milo on 5/27/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

class Solution {
 public:
  int numberOfSpecialChars(string word) {
    bool lower_case[26] = {};
    bool upper_case[26] = {};
    for (char c : word) {
      if (c >= 'a') {
        if (upper_case[c - 'a']) lower_case[c - 'a'] = false;
        else lower_case[c - 'a'] = true;
      } else {
        upper_case[c - 'A'] = true;
      }
    }
    int result = 0;
    for (int i = 0; i < 26; i++) {
      if (lower_case[i] && upper_case[i]) result++;
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  int result = sol.numberOfSpecialChars("aaAbcBC");
  int result_expected = 3;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.numberOfSpecialChars("abc");
  result_expected = 0;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  result = sol.numberOfSpecialChars("abBCab");
  result_expected = 1;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}