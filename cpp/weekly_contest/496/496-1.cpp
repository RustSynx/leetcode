//
// Created by Milo on 4/5/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

class Solution {
public:
  int mirrorFrequency(string s) {
    int result_arr[75] = {0};
    bool check_arr[75] = {false};
    for (char c : s) {
      result_arr[c - '0']++;
    }
    int result = 0;
    for (char c : s) {
      char subtract_val = c >= 96 ? 'a' - '0' : 0;
      char end_val = c >= 96 ? 'z' - '0' : '9' - '0';
      int m_n = abs(result_arr[c - '0'] - result_arr[end_val - (c - subtract_val - '0')]);
      result += !check_arr[end_val - (c - subtract_val - '0')] ? m_n : 0;
      check_arr[c - '0'] = true;
      check_arr[end_val - (c - subtract_val - '0')] = true;
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  int result = sol.mirrorFrequency("ab1z9");
  int result_expected = 3;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.mirrorFrequency("4m7n");
  result_expected = 2;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  result = sol.mirrorFrequency("byby");
  result_expected = 0;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}