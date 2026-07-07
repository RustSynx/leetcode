//
// Created by Milo on 7/7/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

class Solution {
public:
  long long sumAndMultiply(int n) {
    long long result = 0;
    long long idx = 1;
    int sum = 0;
    while (n > 0) {
      int end_num = n % 10;
      if (end_num != 0) {
        result += end_num * idx;
        idx *= 10;
        sum += end_num;
      }
      n /= 10;
    }
    return result * sum;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  long long result = sol.sumAndMultiply(10203004);
  long long result_expected = 12340;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.sumAndMultiply(1000);
  result_expected = 1;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}