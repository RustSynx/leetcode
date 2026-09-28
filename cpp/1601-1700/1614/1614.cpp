//
// Created by Milo on 9/28/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  int maxDepth(string s) {
    int result = 0;
    int curr_max = 0;
    for (char c : s) {
      if (c == '(') {
        curr_max++;
      }
      if (c == ')') {
        result = max(result, curr_max);
        curr_max--;
      }
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  int result = sol.maxDepth("(1+(2*3)+((8)/4))+1");
  int result_expected = 3;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.maxDepth("(1)+((2))+(((3)))");
  result_expected = 3;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  result = sol.maxDepth("()(())((()()))");
  result_expected = 3;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}