//
// Created by Milo on 9/11/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int totalNumbers(vector<int>& digits) {
    int count[10] = {};
    for (int d : digits) {
      count[d]++;
    }
    int valid_count = 0;
    for (int i = 100; i < 1000; i += 2) {
      int a = i / 100;
      int b = i / 10 % 10;
      int c = i % 10;
      count[a]--;
      count[b]--;
      count[c]--;
      if (count[a] >= 0 && count[b] >= 0 && count[c] >= 0) {
        valid_count++;
      }
      count[a]++;
      count[b]++;
      count[c]++;
    }
    return valid_count;
  }
};

int main() {
  Solution sol;
  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> digits = {1, 2, 3, 4};
  int result = sol.totalNumbers(digits);
  int result_expected = 12;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  digits = {0, 2, 2};
  result = sol.totalNumbers(digits);
  result_expected = 2;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  digits = {6, 6, 6};
  result = sol.totalNumbers(digits);
  result_expected = 1;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 4
  cout << "Test Case 4: " << endl;
  digits = {1, 3, 5};
  result = sol.totalNumbers(digits);
  result_expected = 0;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}