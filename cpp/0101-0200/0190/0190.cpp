//
// Created by Milo on 2/16/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

class Solution {
public:
  int reverseBits(int n) {
    int result = 0;
    for (int i = 0; i < 32; i++) {
      int end_bit = n & 1;
      n >>= 1;
      result <<= 1;
      result |= end_bit;
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  int result = sol.reverseBits(43261596);
  int result_expected = 964176192;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.reverseBits(2147483644);
  result_expected = 1073741822;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}