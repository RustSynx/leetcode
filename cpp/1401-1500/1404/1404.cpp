//
// Created by Milo on 2/26/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
  int numSteps(string s) {
    int step_count = 0;
    int carry = 0;

    for (int i = s.length() - 1; i > 0; i--) {
      int sum = s[i] - '0' + carry;

      if (sum % 2 == 0) {
        step_count += 1;
      } else {
        step_count += 2;
        carry = 1;
      }
    }
    return step_count + carry;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  int result = sol.numSteps("1101");
  int result_expected = 6;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.numSteps("10");
  result_expected = 1;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  result = sol.numSteps("1");
  result_expected = 0;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}