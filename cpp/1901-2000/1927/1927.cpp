//
// Created by Milo on 8/23/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  bool sumGame(string num) {
    int n = num.length();
    int left_sum = 0;
    int left_q = 0;
    int right_sum = 0;
    int right_q = 0;
    for (int i = 0; i < n/2; i++) {
      char digit = num[i];
      if (digit != '?') {
        left_sum += digit - '0';
      } else {
        left_q++;
      }
    }
    for (int i = n/2; i < n; i++) {
      char digit = num[i];
      if (digit != '?') {
        right_sum += digit - '0';
      } else {
        right_q++;
      }
    }
    return (right_sum - left_sum) * 2 != (left_q - right_q) * 9;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  bool result = sol.sumGame("5023");
  bool result_expected = false;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.sumGame("25??");
  result_expected = true;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  result = sol.sumGame("?3295???");
  result_expected = false;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}