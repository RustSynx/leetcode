//
// Created by Milo on 3/28/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

class Solution {
 public:
  string findTheString(vector<vector<int>>& lcp) {
    int n = static_cast<int>(lcp.size());
    vector<char> char_vec(n, '0');
    string result = "";
    char init_char = 'a';
    for (int i = 0; i < n; i++) {
      if (char_vec[i] == '0') {
        if (init_char > 'z') return "";
        for (int j = 0; j < n; j++) {
          if (lcp[i][j] > 0) {
            char_vec[j] = init_char;
          }
        }
        init_char++;
      }
    }
    for (char c : char_vec) {
      result += c;
    }
    for (int i = n - 1; i >= 0; i--) {
      for (int j = n - 1; j >= 0; j--) {
        if (i < n - 1 && j < n - 1) {
          if (result[i] == result[j] && lcp[i][j] != lcp[i + 1][j + 1] + 1)
            return "";
          if (result[i] != result[j] && lcp[i][j] != 0) return "";
        } else {
          if (lcp[i][j] != (result[i] == result[j] ? 1 : 0)) return "";
        }
      }
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<vector<int>> input = {
      {4, 0, 2, 0}, {0, 3, 0, 1}, {2, 0, 2, 0}, {0, 1, 0, 1}};
  string result = sol.findTheString(input);
  string result_expected = "abab";
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  input = {{4, 3, 2, 1}, {3, 3, 2, 1}, {2, 2, 2, 1}, {1, 1, 1, 1}};
  result = sol.findTheString(input);
  result_expected = "aaaa";
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  input = {{4, 3, 2, 1}, {3, 3, 2, 1}, {2, 2, 2, 1}, {1, 1, 1, 3}};
  result = sol.findTheString(input);
  result_expected = "";
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}