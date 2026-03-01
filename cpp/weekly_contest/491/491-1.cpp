//
// Created by Milo on 3/1/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

class Solution {
 public:
  string trimTrailingVowels(string s) {
    int trim_index = s.length();
    for (int i = s.length() - 1; i >= 0; i--) {
      if (check_vowel(s[i])) {
        trim_index = i;
      } else {
        break;
      }
    }
    return s.substr(0, trim_index);
  }
  bool check_vowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  string result = sol.trimTrailingVowels("idea");
  string result_expected = "id";
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.trimTrailingVowels("day");
  result_expected = "day";
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.trimTrailingVowels("aeiou");
  result_expected = "";
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}