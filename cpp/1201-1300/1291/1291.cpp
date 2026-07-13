//
// Created by Milo on 7/13/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> sequentialDigits(int low, int high) {
    string digits = "123456789";
    int low_len = to_string(low).length();
    int high_len = to_string(high).length();
    vector<int> result;
    for (int i = low_len; i <= high_len; i++) {
      for (int j = 0; j <= 9 - i; j++) {
        int curr = stoi(digits.substr(j, i));
        if (low <= curr && curr <= high) {
          result.push_back(curr);
        }
      }
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> result = sol.sequentialDigits(100, 300);
  vector<int> result_expected = {123, 234};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.sequentialDigits(1000, 13000);
  result_expected = {1234, 2345, 3456, 4567, 5678, 6789, 12345};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}