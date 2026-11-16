//
// Created by Milo on 11/16/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  string digitSum(string s, int k) {
    while (s.length() > k) {
      string curr_res = "";
      for (int i = 0; i < s.length(); i+=k) {
        int sum = 0;
        for (char c : s.substr(i, k)) {
          sum += c - '0';
        }
        curr_res += to_string(sum);
      }
      s = curr_res;
    }
    return s;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  string result = sol.digitSum("11111222223", 3);
  string result_expected = "135";
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.digitSum("00000000", 3);
  result_expected = "000";
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}