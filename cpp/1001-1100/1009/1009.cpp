//
// Created by Milo on 3/11/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
  int bitwiseComplement(int n) {
    if (n == 0) return 1;
    int bit_mask = 1;
    while (bit_mask < n) {
      bit_mask = (bit_mask << 1) | 1;
    }
    return n ^ bit_mask;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  int result = sol.bitwiseComplement(5);
  int result_expected = 2;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.bitwiseComplement(7);
  result_expected = 0;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  result = sol.bitwiseComplement(10);
  result_expected = 5;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;
  return 0;
}