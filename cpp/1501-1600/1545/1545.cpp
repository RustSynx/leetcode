//
// Created by Milo on 3/3/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

class Solution {
 public:
  char findKthBit(int n, int k) {
    if (n == 1) return '0';
    int mid = 1 << (n - 1);

    if (mid == k) {
      return '1';
    }
    if (mid > k) {
      return findKthBit(n - 1, k);
    } else {
      return findKthBit(n - 1, 2 * mid - k) == '0' ? '1' : '0';
    }
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  char result = sol.findKthBit(3, 1);
  char result_expected = '0';
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.findKthBit(4, 11);
  result_expected = '1';
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}