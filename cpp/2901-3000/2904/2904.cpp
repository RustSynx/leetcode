//
// Created by Milo on 8/26/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  string shortestBeautifulSubstring(string s, int k) {
    int n = s.length();
    string result = "";
    for (int i = 0; i < n; i++) {
      int one_count = 0;
      for (int j = i; j < n; j++) {
        if (s[j] == '1') one_count++;
        if (k == one_count) {
          string curr = s.substr(i, j - i + 1);
          if (result == "" || curr.length() < result.length() ||
              (curr.length() == result.length() && curr < result)) {
            result = curr;
          }
        }
        if (one_count > k) break;
      }
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  string result = sol.shortestBeautifulSubstring("100011001", 3);
  string result_expected = "11001";
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.shortestBeautifulSubstring("1011", 2);
  result_expected = "11";
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  result = sol.shortestBeautifulSubstring("000", 1);
  result_expected = "";
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}