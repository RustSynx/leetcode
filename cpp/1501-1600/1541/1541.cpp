//
// Created by Milo on 10/9/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  int minInsertions(string s) {
    int r_p = 0;
    int result = 0;
    for (char c : s) {
      if (c == '(') {
        if (r_p % 2 != 0) {
          result++;
          r_p--;
        }
        r_p += 2;
      } else {
        r_p--;
        if (r_p < 0) {
          result++;
          r_p += 2;
        }
      }
    }
    return result + r_p;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  int result = sol.minInsertions("(()))");
  int result_expected = 1;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.minInsertions("())");
  result_expected = 0;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  result = sol.minInsertions("))())(");
  result_expected = 3;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}