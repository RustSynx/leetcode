//
// Created by Milo on 3/29/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

class Solution {
 public:
  bool canBeEqual(string s1, string s2) {
    return (s1[0] == s2[0] || s1[0] == s2[2]) &&
           (s1[2] == s2[0] || s1[2] == s2[2]) &&
           (s1[1] == s2[1] || s1[1] == s2[3]) &&
           (s1[3] == s2[1] || s1[3] == s2[3]);
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  bool result = sol.canBeEqual("abcd", "cdab");
  bool result_expected = true;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.canBeEqual("abcd", "dacb");
  result_expected = false;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}