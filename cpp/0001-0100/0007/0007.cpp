//
// Created by Milo on 2/5/26.
//
#include <algorithm>
#include <cassert>
#include <deque>
#include <iostream>

using namespace std;

class Solution {
 public:
  int reverse(int x) {
    if (x == INT_MIN) return 0;
    string max = "2147483647";
    string sign = x < 0 ? "-" : "";
    string input_string = to_string(abs(x));
    int length = input_string.length();
    deque<char> reverse_deque;
    int over_count = 1;
    for (int i = 0; i < length; i++) {
      if (input_string.length() >= max.length() && input_string[length - i - 1] >= max[i]) {
        if (input_string[length - i - 1] > max[i] && over_count == i + 1) {
          return 0;
        }
        over_count++;
      }
      if (reverse_deque.empty() && input_string[length - i - 1] == '0')
        continue;
      reverse_deque.push_back(input_string[length - i - 1]);
    }
    string result;
    for (char c : reverse_deque) {
      result += c;
    }
    result = sign + result;
    return stoi(result);
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  int result = sol.reverse(123);
  int result_expected = 321;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.reverse(-123);
  result_expected = -321;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  result = sol.reverse(120);
  result_expected = 21;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}