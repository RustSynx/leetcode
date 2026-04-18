//
// Created by Milo on 4/18/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

class Solution {
public:
  int mirrorDistance(int n) {
    return abs(n - reverseInteger(n));
  }
  int reverseInteger(int num) {
    long long reversed_num = 0;
    while (num > 0) {
      reversed_num = reversed_num * 10 + (num % 10);
      num /= 10;
    }
    return static_cast<int>(reversed_num);
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  int result = sol.mirrorDistance(25);
  int result_expected = 27;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.mirrorDistance(10);
  result_expected = 9;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  result = sol.mirrorDistance(7);
  result_expected = 0;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}