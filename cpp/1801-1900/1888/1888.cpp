//
// Created by Milo on 3/7/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

class Solution {
public:
  int minFlips(string s) {
    string search_range = s + s;
    int result = INT_MAX;
    string pattern_one;
    pattern_one.reserve(search_range.length());
    string pattern_two;
    pattern_two.reserve(search_range.length());
    for (int i = 0; i < search_range.length(); i++) {
      pattern_one += static_cast<char>(i % 2 + '0');
      pattern_two += static_cast<char>((i + 1) % 2 + '0');
    }
    int pattern_one_count = 0;
    int pattern_two_count = 0;
    for (int i = 0; i < s.length(); i++) {
      if (search_range[i] != pattern_one[i]) pattern_one_count++;
      if (search_range[i] != pattern_two[i]) pattern_two_count++;
    }
    result = min({result, pattern_one_count, pattern_two_count});
    for (int i = 0; i < s.length(); i++) {
      if (search_range[i] != pattern_one[i]) pattern_one_count--;
      if (search_range[s.length() + i] != pattern_one[s.length() + i]) pattern_one_count++;
      if (search_range[i] != pattern_two[i]) pattern_two_count--;
      if (search_range[s.length() + i] != pattern_two[s.length() + i]) pattern_two_count++;
      result = min({result, pattern_one_count, pattern_two_count});
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  int result = sol.minFlips("111000");
  int result_expected = 2;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.minFlips("010");
  result_expected = 0;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  result = sol.minFlips("1110");
  result_expected = 1;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}