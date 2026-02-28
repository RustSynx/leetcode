//
// Created by Milo on 2/28/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <bit>

using namespace std;

class Solution {
public:
  int concatenatedBinary(int n) {
    auto modular_constant = static_cast<int>(1e9 + 7);
    long long result = 0;
    for (unsigned int i = 1; i <= n; i++) {
      auto length = std::bit_width(i);
      result = ((result << length) + i) % modular_constant;
    }
    return static_cast<int>(result);
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  int result = sol.concatenatedBinary(1);
  int result_expected = 1;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.concatenatedBinary(3);
  result_expected = 27;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  result = sol.concatenatedBinary(12);
  result_expected = 505379714;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}