//
// Created by Milo on 6/17/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  char processStr(string s, long long k) {
    int n = static_cast<int>(s.length());
    string result;
    long long len = 0;
    vector<long long> len_vec(n);
    for (int i = 0; i < n; i++) {
      char c = s[i];
      switch (c) {
        case '*':
          if (len > 0) len--;
          break;
        case '%':
          break;
        case '#':
          if (len > 1e15)
            len = 1e15;
          else
            len += len;
          break;
        default:
          len++;
      }
      len_vec[i] = len;
    }
    if (k < 0 || k >= len) return '.';
    for (int i = n - 1; i >= 0; i--) {
      char c = s[i];
      long long prev_len = i == 0 ? 0 : len_vec[i - 1];
      switch (c) {
        case '*':
          break;
        case '#':
          if (k >= prev_len) {
            k = k - prev_len;
          }
          break;
        case '%':
          if (prev_len > 0) k = prev_len - 1 - k;
          break;
        default:
          if (k == prev_len) return c;
      }
    }
    return '.';
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  char result = sol.processStr("a#b%*", 1);
  char result_expected = 'a';
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.processStr("cd%#*#", 3);
  result_expected = 'd';
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.processStr("z*#", 0);
  result_expected = '.';
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}