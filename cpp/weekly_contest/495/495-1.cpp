//
// Created by Milo on 3/29/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

class Solution {
public:
  int firstMatchingIndex(string s) {
    int n = static_cast<int>(s.length());
    char min_char = 'z';
    int result = INT_MAX;
    for (int i = 0; i <= n / 2; i++) {
      if (s[i] == s[n - i - 1] && min_char >= s[i]) {
        result = min(result, i);
        min_char = s[i];
      }
    }
    return result == INT_MAX ? -1 : result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  int result = sol.firstMatchingIndex("abcacbd");
  int result_expected = 1;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.firstMatchingIndex("abc");
  result_expected = 1;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.firstMatchingIndex("abcdab");
  result_expected = -1;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}