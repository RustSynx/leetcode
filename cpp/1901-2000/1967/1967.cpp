//
// Created by Milo on 6/29/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int numOfStrings(vector<string>& patterns, string word) {
    int result = 0;
    for (const string& pattern : patterns) {
      if (word.find(pattern) != string::npos) {
        result++;
      }
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<string> patterns = {"a","abc","bc","d"};
  int result = sol.numOfStrings(patterns, "abc");
  int result_expected = 3;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  patterns = {"a","b","c"};
  result = sol.numOfStrings(patterns, "aaaaabbbbb");
  result_expected = 2;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  patterns = {"a","a","a"};
  result = sol.numOfStrings(patterns, "ab");
  result_expected = 3;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}