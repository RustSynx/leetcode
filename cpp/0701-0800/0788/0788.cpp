//
// Created by Milo on 5/2/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

class Solution {
public:
  int rotatedDigits(int n) {
    int result = 0;
    for (int i = 2; i <= n; i++) {
      if (checkGoodNumber(i)) {
        result++;
      }
    }
    return result;
  }
  bool checkGoodNumber(int n) {
    bool good_number = false;
    while (n > 0) {
      int num = n % 10;
      if (num == 3 || num == 4 || num == 7) return false;
      if (num == 2 || num == 5 || num == 6 || num == 9) good_number = true;
      n /= 10;
    }
    return good_number;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  int result = sol.rotatedDigits(10);
  int result_expected = 4;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.rotatedDigits(1);
  result_expected = 0;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  result = sol.rotatedDigits(2);
  result_expected = 1;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}