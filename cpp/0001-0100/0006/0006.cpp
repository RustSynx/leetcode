//
// Created by Milo on 2/7/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  string convert(string s, int numRows) {
    vector<vector<char>> resultVector(numRows, vector<char>(s.length(), '-'));
    string result = "";
    int columnIndex = 0;
    for (int i = 0; i < s.length(); i++) {
      resultVector[columnIndex].push_back(s[i]);
      if (numRows != 1) {
        if ((i / (numRows - 1)) % 2 != 0) {
          columnIndex--;
        } else {
          columnIndex++;
        }
      }
    }
    for (int i = 0; i < numRows; i++) {
      for (char c : resultVector[i]) {
        if (c != '-') result += c;
      }
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  string result = sol.convert("PAYPALISHIRING", 3);
  string result_expected = "PAHNAPLSIIGYIR";
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.convert("PAYPALISHIRING", 4);
  result_expected = "PINALSIGYAHRPI";
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  result = sol.convert("A", 1);
  result_expected = "A";
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}