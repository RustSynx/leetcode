//
// Created by Milo on 7/21/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int maxActiveSectionsAfterTrade(string s) {
    int total_ones = 0;
    int current_zero_len = 0;
    vector<int> zero_lengths;
    for (char c : s) {
      if (c == '1') total_ones++;
      if (current_zero_len != 0 && c == '1') {
        zero_lengths.push_back(current_zero_len);
        current_zero_len = 0;
      }
      if (c == '0') current_zero_len++;
    }
    if (current_zero_len != 0) zero_lengths.push_back(current_zero_len);
    int max_combined_zeros = 0;
    for (int i = 0; i + 1 < zero_lengths.size(); i++) {
      max_combined_zeros = max(max_combined_zeros, zero_lengths[i] + zero_lengths[i + 1]);
    }
    return total_ones + max_combined_zeros;
  }
};

int main() {
  Solution sol;
  // Test Case 1
  cout << "Test Case 1: " << endl;
  int result = sol.maxActiveSectionsAfterTrade("01");
  int result_expected = 1;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.maxActiveSectionsAfterTrade("0100");
  result_expected = 4;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  result = sol.maxActiveSectionsAfterTrade("1000100");
  result_expected = 7;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 4
  cout << "Test Case 4: " << endl;
  result = sol.maxActiveSectionsAfterTrade("01010");
  result_expected = 4;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}