//
// Created by Milo on 10/21/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  int minOperations(string s) {
    if (ranges::is_sorted(s)) {
      return 0;
    }
    int n = s.length();
    if (n == 2) return -1;
    auto [min_c, max_c] = minmax_element(s.begin(), s.end());
    int max_count = ranges::count(s, *max_c);
    int min_count = ranges::count(s, *min_c);
    if (*max_c == s[0] && *min_c == s.back() && max_count == 1 &&
        min_count == 1)
      return 3;
    if (*min_c == s[0] || *max_c == s.back()) return 1;
    return 2;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  int result = sol.minOperations("dog");
  int result_expected = 1;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.minOperations("card");
  result_expected = 2;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  result = sol.minOperations("gf");
  result_expected = -1;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}