//
// Created by Milo on 7/15/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

class Solution {
public:
  int gcdOfOddEvenSums(int n) {
    return n;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  int result = sol.gcdOfOddEvenSums(4);
  int result_expected = 4;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.gcdOfOddEvenSums(5);
  result_expected = 5;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}