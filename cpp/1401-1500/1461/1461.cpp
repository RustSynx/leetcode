//
// Created by Milo on 2/23/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
  bool hasAllCodes(string s, int k) {
    if (s.size() < k) return false;

    int every_binary_count = 1 << k;
    int current_binary = 0;
    int check_binary = every_binary_count - 1;
    unordered_set<int> check_duplications;
    for (int i = 0; i < s.size(); i++) {
      current_binary <<= 1;
      current_binary |= s[i] - '0';
      current_binary &= check_binary;
      if (i >= (k - 1) && current_binary < every_binary_count) {
        check_duplications.insert(current_binary);
      }
    }
    if (every_binary_count == check_duplications.size()) return true;
    return false;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  bool result = sol.hasAllCodes("00110110", 2);
  bool result_expected = true;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.hasAllCodes("0110", 1);
  result_expected = true;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  result = sol.hasAllCodes("0110", 2);
  result_expected = false;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}