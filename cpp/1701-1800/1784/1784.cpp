//
// Created by Milo on 3/6/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

class Solution {
public:
  bool checkOnesSegment(string s) {
    char prev_char = s[0];
    int change_count = 0;
    for (int i = 1; i < s.size(); i++) {
      char current_char = s[i];
      if (prev_char == '0' && current_char == '1') {
        change_count++;
      }
      prev_char = current_char;
    }
    if (change_count > 0) return false;
    return true;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  bool result = sol.checkOnesSegment("1001");
  bool result_expected = false;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.checkOnesSegment("110");
  result_expected = true;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}