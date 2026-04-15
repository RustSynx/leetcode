//
// Created by Milo on 4/15/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int closestTarget(vector<string>& words, string target, int startIndex) {
    int n = static_cast<int>(words.size());
    int result = INT_MAX;
    if (words[startIndex] == target) return 0;
    for (int i = 1; i < n; i++) {
      if (words[(startIndex + i) % n] == target) {
        result = min(result, i);
      }
      if (words[(startIndex - i + n) % n] == target) {
        result = min(result, i);
      }
    }
    return result == INT_MAX ? -1 : result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<string> words = {"hello","i","am","leetcode","hello"};
  int result = sol.closestTarget(words, "hello", 1);
  int result_expected = 1;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  words = {"a","b","leetcode"};
  result = sol.closestTarget(words, "leetcode", 0);
  result_expected = 1;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  words = {"i","eat","leetcode"};
  result = sol.closestTarget(words, "ate", 0);
  result_expected = -1;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}