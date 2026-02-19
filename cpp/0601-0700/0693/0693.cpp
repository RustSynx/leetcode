//
// Created by Milo on 2/18/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

class Solution {
public:
  bool hasAlternatingBits(int n) {
    while (n > 0) {
      int last_bit = n & 1;
      n >>= 1;
      if (last_bit == (n & 1)) return false;
    }
    return true;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  bool result = sol.hasAlternatingBits(5);
  bool result_expected = true;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.hasAlternatingBits(7);
  result_expected = false;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;


  // Test Case 3
  cout << "Test Case 3: " << endl;
  result = sol.hasAlternatingBits(11);
  result_expected = false;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}