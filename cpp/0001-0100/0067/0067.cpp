//
// Created by Milo on 2/15/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

class Solution {
public:
  string addBinary(string a, string b) {
    while (a.size() != b.size()) {
      if (a.size() > b.size()) {
        b = '0' + b;
      } else {
        a = '0' + a;
      }
    }
    string result = "";
    int carry = 0;
    cout << a << " " << b << endl;
    for (int i = a.size() - 1; i >= 0; i--) {
      int sum = (a[i] - '0') + (b[i] - '0') + carry;
      result = (char)(sum % 2 + '0') + result;
      carry = sum / 2;
    }
    if (carry) return "1" + result;
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  string result = sol.addBinary("11", "1");
  string result_expected = "100";
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.addBinary("1010", "1011");
  result_expected = "10101";
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}