//
// Created by Milo on 5/17/26.
//
#include <cassert>
#include <iostream>

using namespace std;

class Solution {
public:
  int countKthRoots(int l, int r, int k) {
    if (k == 1) return r - l + 1;
    int count = 0;
    for (long long i = 0; i <= r; i++) {
      long long power = 1;
      for (long long j = 0; j < k; j++) {
        power *= i;
        if (power > r) break;
      }
      if (power > r) break;
      if (power >= l) count++;
    }
    return count;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  int result = sol.countKthRoots(1, 9, 3);
  int result_expected = 2;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.countKthRoots(8, 30, 2);
  result_expected = 3;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}