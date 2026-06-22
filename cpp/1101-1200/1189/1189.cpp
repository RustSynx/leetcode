//
// Created by Milo on 6/22/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

class Solution {
public:
  int maxNumberOfBalloons(string text) {
    int char_count[26] = {0};
    for (char c : text) {
      char_count[c - 'a']++;
    }
    return min({
      char_count['b' - 'a'],
      char_count['a' - 'a'],
      char_count['l' - 'a'] / 2,
      char_count['o' - 'a'] / 2,
      char_count['n' - 'a'],
    });
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  int result = sol.maxNumberOfBalloons("nlaebolko");
  int result_expected = 1;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.maxNumberOfBalloons("loonbalxballpoon");
  result_expected = 2;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  result = sol.maxNumberOfBalloons("leetcode");
  result_expected = 0;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}