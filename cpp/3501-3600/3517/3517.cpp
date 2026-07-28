//
// Created by Milo on 7/28/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  string smallestPalindrome(string s) {
    int n = s.length();
    if (n == 1) return s;
    int char_count[26] = {0};
    for (char c : s) {
      char_count[c - 'a']++;
    }
    string result;
    result.reserve(n);
    string middle = "";
    for (int i = 0; i < 26; i++) {
      int count = char_count[i];
      if (count % 2 == 1) middle = 'a' + i;
      result.append(count / 2, 'a' + i);
    }
    string reversed(result.rbegin(), result.rend());
    return result + middle + reversed;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  string result = sol.smallestPalindrome("z");
  string result_expected = "z";
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.smallestPalindrome("babab");
  result_expected = "abbba";
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  result = sol.smallestPalindrome("daccad");
  result_expected = "acddca";
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}