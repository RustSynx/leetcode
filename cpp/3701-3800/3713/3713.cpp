//
// Created by Milo on 2/12/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
 public:
  int longestBalanced(string s) {
    unordered_set<char> distinct_chars(s.begin(), s.end());
    int result = 0;
    int max_unique_char = distinct_chars.size();
    int input_length = s.length();

    for (int unique_count = 1; unique_count <= max_unique_char; unique_count++) {
      for (int repeat_count = 1; repeat_count * unique_count <= input_length; repeat_count++) {
        int window_size = unique_count * repeat_count;
        unordered_map<char, int> char_count;
        int unique_in_window = 0;
        int balanced_count = 0;

        for (int start = 0; start < window_size; start++) {
          if (char_count[s[start]] == 0) unique_in_window++;
          char_count[s[start]]++;
          if (char_count[s[start]] == repeat_count) balanced_count++;
          else if (char_count[s[start]] == repeat_count + 1) balanced_count--;
        }

        if (unique_in_window == unique_count && balanced_count == unique_count) {
          result = max(result, window_size);
        }

        for (int start = window_size; start < input_length; start++) {
          if (char_count[s[start]] == 0) unique_in_window++;
          char_count[s[start]]++;
          if (char_count[s[start]] == repeat_count) balanced_count++;
          else if (char_count[s[start]] == repeat_count + 1) balanced_count--;

          if (char_count[s[start - window_size]] == repeat_count) balanced_count--;
          char_count[s[start - window_size]]--;
          if (char_count[s[start - window_size]] == 0) unique_in_window--;
          else if (char_count[s[start - window_size]] == repeat_count) balanced_count++;

          if (unique_in_window == unique_count && balanced_count == unique_count) {
            result = max(result, window_size);
          }
        }
      }
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  int result = sol.longestBalanced("abbac");
  int result_expected = 4;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.longestBalanced("zzabccy");
  result_expected = 4;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  result = sol.longestBalanced("aba");
  result_expected = 2;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}