//
// Created by Milo on 2/5/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

class Solution {
public:
  string longestPalindrome(string s) {
    if (s.empty()) return "";
    int length = 1;
    int start = 0;
    for (int i = 0; i < s.length(); i++) {
      checkPalindrome(s, start, i, i, length);
      checkPalindrome(s, start, i, i + 1, length);
    }
    return s.substr(start, length);
  }

  void checkPalindrome(string s, int& start, int left, int right, int& length) {
    while (left >= 0 && right < s.length() && s[left] == s[right]) {
      int currentLength = right - left + 1;
      if (currentLength > length) {
        start = left;
        length = currentLength;
      }
      left--;
      right++;
    }
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: ";
  string result = sol.longestPalindrome("babad");
  string result_expected = "bab";
  assert(result == result_expected);
  cout << " PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: ";
  result = sol.longestPalindrome("cbbd");
  result_expected = "bb";
  assert(result == result_expected);
  cout << " PASSED" << endl;

  return 0;
}