//
// Created by Milo on 2/22/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool isDigitorialPermutation(int n) {
    vector<int> factorials = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
    string num_string = to_string(n);
    int sum = 0;
    for (char num_char : num_string) {
      sum += factorials[num_char - '0'];
    }
    string sum_string = to_string(sum);
    sort(sum_string.begin(), sum_string.end(), greater<char>());
    sort(num_string.begin(), num_string.end(), greater<char>());
    if (sum_string == num_string) return true;
    return false;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  int result = sol.isDigitorialPermutation(145);
  bool result_expected = true;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.isDigitorialPermutation(10);
  result_expected = false;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}