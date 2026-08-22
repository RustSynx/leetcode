//
// Created by Milo on 8/22/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

class Solution {
public:
  bool checkDivisibility(int n) {
    int original = n;
    int sum = 0;
    int product = 1;
    while (n > 0) {
      int digit = n % 10;
      sum += digit;
      product *= digit;
      n /= 10;
    }
    return original % (sum + product) == 0;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  bool result = sol.checkDivisibility(99);
  bool result_expected = true;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.checkDivisibility(23);
  result_expected = false;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}