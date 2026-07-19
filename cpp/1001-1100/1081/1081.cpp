//
// Created by Milo on 7/19/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  string smallestSubsequence(string s) {
    vector<int> letter_idx(26, -1);
    vector<bool> letter_in(26, false);
    int n = s.length();

    for (int i = 0; i < n; i++) {
      letter_idx[s[i] - 'a'] = i;
    }

    string result;
    for (int i = 0; i < n; i++) {
      char c = s[i];

      if (letter_in[c - 'a']) continue;

      while (!result.empty() && result.back() > c &&
             i < letter_idx[result.back() - 'a']) {
        letter_in[result.back() - 'a'] = false;
        result.pop_back();
      }
      letter_in[c - 'a'] = true;
      result.push_back(c);
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  string result = sol.smallestSubsequence("bcabc");
  string result_expected = "abc";
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.smallestSubsequence("cbacdcbc");
  result_expected = "acdb";
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;
  return 0;
}