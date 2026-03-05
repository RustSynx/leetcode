//
// Created by Milo on 3/5/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

class Solution {
public:
  int minOperations(string s) {
    int result = 0;
    for (int i = 0; i < s.size(); i++) {
      if ((i % 2 == 0 && s[i] == '0') || (i % 2 != 0 && s[i] == '1')) {
        result++;
      }
    }
    return min(result, static_cast<int>(s.size()) - result);
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  int result = sol.minOperations("0100");
  int result_expected = 1;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.minOperations("10");
  result_expected = 0;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  result = sol.minOperations("1111");
  result_expected = 2;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}