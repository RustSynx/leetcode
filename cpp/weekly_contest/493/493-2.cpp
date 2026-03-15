//
// Created by Milo on 3/15/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

class Solution {
public:
  long long countCommas(long long n) {
    if (n < 1000) return 0;
    long long comma_count = n - 999LL;
    if (n >= 1000000LL) comma_count += n - 999999LL;
    if (n >= 1000000000LL) comma_count += n - 999999999LL;
    if (n >= 1000000000000LL) comma_count += n - 999999999999LL;
    if (n >= 1000000000000000LL) comma_count += n - 999999999999999LL;
    return comma_count;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  int result = sol.countCommas(1002);
  int result_expected = 3;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.countCommas(998);
  result_expected = 0;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}