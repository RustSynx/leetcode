//
// Created by Milo on 8/14/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  int maximumLengthSubstring(string s) {
    int n = s.length();
    int letters[26] = {};
    int result = 0;
    int left = 0;
    int right = 0;
    while (right < n) {
      int c = s[right] - 'a';
      if (letters[c] < 2) {
        letters[c]++;
        result = max(result, right - left + 1);
        right++;
      } else {
        letters[s[left] - 'a']--;
        left++;
      }
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  int result = sol.maximumLengthSubstring("bcbbbcba");
  int result_expected = 4;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.maximumLengthSubstring("aaaa");
  result_expected = 2;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}