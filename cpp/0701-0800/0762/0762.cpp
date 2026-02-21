//
// Created by Milo on 2/21/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

class Solution {
public:
  int countPrimeSetBits(int left, int right) {
    int result = 0;
    for (int i = left; i <= right; i++) {
      int set_bits_count = 0;
      int check_number = i;
      for (int j = 0; j < 32; j++) {
        if ((check_number & 1) == 1) {
          set_bits_count++;
        }
        check_number >>= 1;
      }
      if (check_prime(set_bits_count)) {
        result++;
      }
    }
    return result;
  }
  bool check_prime(int num) {
    if (num == 1) return false;
    int result = static_cast<int>(std::sqrt(num));
    for (int i = 2; i <= result; i++) {
        if (num % i == 0) return false;
    }
    return true;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  int result = sol.countPrimeSetBits(6, 10);
  int result_expected = 4;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.countPrimeSetBits(10, 15);
  result_expected = 5;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}