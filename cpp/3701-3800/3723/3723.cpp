//
// Created by Milo on 10/14/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  string maxSumOfSquares(int num, int sum) {
    if (num * 9 < sum) return "";
    string result = "";
    for (int i = 0; i < num; i++) {
      int digit = min(9, sum);
      result += '0' + digit;
      sum -= digit;
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  string result = sol.maxSumOfSquares(2, 3);
  string result_expected = "30";
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.maxSumOfSquares(2, 17);
  result_expected = "98";
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  result = sol.maxSumOfSquares(1, 10);
  result_expected = "";
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}