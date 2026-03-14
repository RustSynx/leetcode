//
// Created by Milo on 3/14/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
  unordered_map<char, vector<char>> static_string = {
    {'a', {'b', 'c'}},
    {'b', {'a', 'c'}},
    {'c', {'a', 'b'}},
  };
  string getHappyString(int n, int k) {
    vector<string> result;
    string current_string;
    makeString(current_string, n, k, result);
    if (k > result.size()) {
      return "";
    }
    return result[k-1];
  }
  void makeString(string& current_string, int n, int k, vector<string>& result) {
    if (k == result.size()) return;
    if (current_string.length() == n) {
      result.push_back(current_string);
      return;
    }
    if (current_string.empty()) {
      for (char c : {'a', 'b', 'c'}) {
        current_string.push_back(c);
        makeString(current_string, n, k, result);
        current_string.pop_back();
      }
      return;
    }
    for (int i = 0; i < 2; i++) {
      char last_string = current_string.back();
      current_string.push_back(static_string[last_string][i]);
      makeString(current_string, n, k, result);
      current_string.pop_back();
    }
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  string result = sol.getHappyString(1, 3);
  string result_expected = "c";
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.getHappyString(1, 4);
  result_expected = "";
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  result = sol.getHappyString(3, 9);
  result_expected = "cab";
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}