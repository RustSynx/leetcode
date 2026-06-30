//
// Created by Milo on 6/30/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

class Solution {
public:
  int numberOfSubstrings(string s) {
    vector<int> cnt(3);
    int result = 0;
    int start = 0;
    int end = 0;
    while (start <= end && end < s.length()) {
      cnt[s[end] - 'a']++;
      if (cnt[0] > 0 && cnt[1] > 0 && cnt[2] > 0) {
        while (cnt[s[start] - 'a'] > 1) {
          cnt[s[start] - 'a']--;
          start++;
        }
        result += start + 1;
      }
      end++;
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  int result = sol.numberOfSubstrings("abcabc");
  int result_expected = 10;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.numberOfSubstrings("aaacb");
  result_expected = 3;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  result = sol.numberOfSubstrings("abc");
  result_expected = 1;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}