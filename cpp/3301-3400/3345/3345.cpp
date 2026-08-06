//
// Created by Milo on 8/6/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

class Solution {
public:
  int smallestNumber(int n, int t) {
    while (true) {
      int product = 1;
      int curr = n;
      while (curr > 0) {
        product *= curr % 10;
        curr /= 10;
      }
      if (product % t == 0) return n;
      n++;
    }
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  int result = sol.smallestNumber(10, 2);
  int result_expected = 10;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.smallestNumber(15, 3);
  result_expected = 16;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}