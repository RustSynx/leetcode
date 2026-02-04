//
// Created by Milo on 2/4/26.
//
#include <cassert>
#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int start = 0, max = 0, result = 0;
    unordered_set<char> set;
    for (int i = 0; start != s.size(); i++) {
      if (set.find(s[i]) != set.end() || i == s.size()) {
        ++start;
        i = start - 1;
        set.clear();
        if (max > result) {
          result = max;
        }
        max = 0;
        continue;
      }
      set.insert(s[i]);
      max++;
    }
    return result;
  }
};


int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: ";
  int result = sol.lengthOfLongestSubstring("abcabcbb");
  int result_expected = 3;
  assert(result == result_expected);
  cout << " PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: ";
  result = sol.lengthOfLongestSubstring("bbbbb");
  result_expected = 1;
  assert(result == result_expected);
  cout << " PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: ";
  result = sol.lengthOfLongestSubstring("pwwkew");
  result_expected = 3;
  assert(result == result_expected);
  cout << " PASSED" << endl;

  return 0;
}