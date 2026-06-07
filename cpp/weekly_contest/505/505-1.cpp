//
// Created by Milo on 6/7/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

class Solution {
public:
  int sumOfGoodIntegers(int n, int k) {
    int result = 0;
    int start = max(1, n - k);
    int end = n + k;
    for (int x = start; x <= end; x++) {
      if ((n & x) == 0) {
        result += x;
      }
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  int result = sol.sumOfGoodIntegers(2, 3);
  int result_expected = 10;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.sumOfGoodIntegers(5, 1);
  result_expected = 0;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}