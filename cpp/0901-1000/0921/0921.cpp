//
// Created by Milo on 10/6/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
  int minAddToMakeValid(string s) {
    int result = 0;
    int open = 0;
    for (char c : s) {
      if (c == '(') open++;
      else open--;
      if (open < 0) {
        open = 0;
        result++;
      }
    }
    return result + open;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  int result = sol.minAddToMakeValid("())");
  int result_expected = 1;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.minAddToMakeValid("(((");
  result_expected = 3;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}