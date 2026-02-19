//
// Created by Milo on 2/19/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

class Solution {
public:
  int countBinarySubstrings(string s) {
    char prev_char = s[0];
    int prev_count = 0;
    int current_count = 0;
    int result = 0;
    for (int i = 0; i < s.size(); i++) {
      if (prev_char != s[i]) {
        prev_char = s[i];
        prev_count = current_count;
        current_count = 0;
      }
      current_count++;
      if (prev_count >= current_count) {
        result++;
      }
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  int result = sol.countBinarySubstrings("00110011");
  int result_expected = 6;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.countBinarySubstrings("10101");
  result_expected = 4;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}