//
// Created by Milo on 6/4/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

class Solution {
public:
  int totalWaviness(int num1, int num2) {
    if (num2 <= 100) return 0;
    int result = 0;
    while (num1 <= num2) {
      string num_str = to_string(num1);
      int len = max(static_cast<int>(num_str.length()) - 2,0);
      for (int i = 1; i <= len; i++) {
        if (num_str[i-1] < num_str[i] && num_str[i] > num_str[i+1]) {
          result++;
        }
        if (num_str[i-1] > num_str[i] && num_str[i] < num_str[i+1]) {
          result++;
        }
      }
      num1++;
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  int num1 = 120;
  int num2 = 130;
  int result = sol.totalWaviness(num1, num2);
  int result_expected = 3;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  num1 = 198;
  num2 = 202;
  result = sol.totalWaviness(num1, num2);
  result_expected = 3;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  num1 = 4848;
  num2 = 4848;
  result = sol.totalWaviness(num1, num2);
  result_expected = 2;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}