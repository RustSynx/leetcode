//
// Created by Milo on 7/29/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  long long nCr(int n, int r) {
    if (r > n - r) r = n - r;
    long long res = 1;
    for (int i = 1; i <= r; i++) {
      res = res * (n - i + 1) / i;
      if (res > 1e6) return 1000001;
    }
    return res;
  }

  long long getPermutations(int char_count[], int len) {
    long long ways = 1;
    for (int i = 0; i < 26; i++) {
      if (char_count[i] == 0) continue;
      ways *= nCr(len, char_count[i]);
      if (ways > 1000000) return 1000001;
      len -= char_count[i];
    }
    return ways;
  }
  string smallestPalindrome(string s, int k) {
    int char_count[26] = {0};
    for (char c : s) {
      char_count[c - 'a']++;
    }
    string middle = "";
    int total_char = 0;
    for (int i = 0; i < 26; i++) {
      if (char_count[i] % 2 == 1) middle = 'a' + i;
      char_count[i] = char_count[i] / 2;
      total_char += char_count[i];
    }
    if (getPermutations(char_count, total_char) < k) {
      return "";
    }
    string result;
    result.reserve(total_char);
    int len = total_char;
    for (int i = 0; i < len; i++) {
      for (int j = 0; j < 26; j++) {
        if (char_count[j] > 0) {
          char_count[j]--;
          long long ways = getPermutations(char_count, total_char - 1);
          if (k <= ways) {
            result += 'a' + j;
            total_char--;
            break;
          }
          k -= ways;
          char_count[j]++;
        }
      }
    }
    string reversed(result.rbegin(), result.rend());
    return result + middle + reversed;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  string result = sol.smallestPalindrome("abba", 2);
  string result_expected = "baab";
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.smallestPalindrome("aa", 2);
  result_expected = "";
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  result = sol.smallestPalindrome("bacab", 1);
  result_expected = "abcba";
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}