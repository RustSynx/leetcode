//
// Created by Milo on 8/27/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  string lexGreaterPermutation(string s, string target) {
    int n = s.length();
    int s_count[26] = {};
    for (int i = 0; i < n; i++) {
      s_count[s[i] - 'a']++;
    }
    int best_idx = -1;
    char best_char = 0;

    for (int i = 0; i < n; i++) {
      char curr = target[i];
      for (int j = curr - 'a' + 1; j < 26; j++) {
        if (s_count[j] > 0) {
          best_idx = i;
          best_char = j + 'a';
          break;
        }
      }
      if (s_count[curr - 'a'] > 0) {
        s_count[curr - 'a']--;
      } else {
        break;
      }
    }

    if (best_idx == -1) {
      return "";
    }

    string result = target.substr(0, best_idx);
    result += best_char;

    memset(s_count, 0, sizeof(s_count));
    for (char c : s) s_count[c - 'a']++;
    for (char c : result) s_count[c - 'a']--;

    for (int i = 0; i < 26; i++) {
      while (s_count[i] > 0) {
        result += i + 'a';
        s_count[i]--;
      }
    }

    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  string result = sol.lexGreaterPermutation("abc", "bba");
  string result_expected = "bca";
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.lexGreaterPermutation("leet", "code");
  result_expected = "eelt";
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  result = sol.lexGreaterPermutation("baba", "bbaa");
  result_expected = "";
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}