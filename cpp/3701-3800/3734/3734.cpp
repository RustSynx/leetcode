//
// Created by Milo on 8/28/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string lexPalindromicPermutation(string s, string target) {
    int n = s.length();
    vector<int> s_count(26);
    for (char c : s) {
      s_count[c - 'a']++;
    }
    bool is_odd = false;
    char odd_char = 0;
    for (int i = 0; i < 26; i++) {
      if (s_count[i] % 2 != 0) {
        if (is_odd) return "";
        is_odd = true;
        odd_char = i + 'a';
      }
    }
    for (int i = 0; i < 26; i ++) {
      s_count[i] /= 2;
    }

    bool can_match = true;
    vector<int> temp_count = s_count;

    for (int i = 0; i < n / 2; i++) {
      int idx = target[i] - 'a';
      if (temp_count[idx] > 0) {
        temp_count[idx]--;
      } else {
        can_match = false;
        break;
      }
    }

    if (can_match) {
      string pal = target.substr(0, n / 2);
      if (n % 2 != 0) pal += odd_char;

      string right = target.substr(0, n / 2);
      reverse(right.begin(), right.end());
      pal += right;

      if (pal > target) {
        return pal;
      }
    }

    int best_idx = -1;
    char best_char = 0;
    vector<int> best_count = s_count;
    for (int i = 0; i < n / 2; i++) {
      char curr = target[i];
      for (int j = curr - 'a' + 1; j < 26; j++) {
        if (best_count[j] > 0) {
          best_idx = i;
          best_char = j + 'a';
          break;
        }
      }
      if (best_count[curr - 'a'] > 0) {
        best_count[curr - 'a']--;
      } else {
        break;
      }
    }
    if (best_idx == -1) return "";
    string left_str = target.substr(0, best_idx);
    for (char c : left_str) {
      s_count[c - 'a']--;
    }
    left_str += best_char;
    s_count[best_char - 'a']--;

    for (int i = 0; i < 26; i++) {
      while (s_count[i] > 0) {
        left_str += i + 'a';
        s_count[i]--;
      }
    }

    string result = left_str;
    if (n % 2 != 0) result += odd_char;
    string right_str = left_str;
    ranges::reverse(right_str.begin(), right_str.end());
    result += right_str;
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  string result = sol.lexPalindromicPermutation("baba", "abba");
  string result_expected = "baab";
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.lexPalindromicPermutation("baba", "bbaa");
  result_expected = "";
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  result = sol.lexPalindromicPermutation("abc", "abb");
  result_expected = "";
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 4
  cout << "Test Case 4: " << endl;
  result = sol.lexPalindromicPermutation("aac", "abb");
  result_expected = "aca";
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}