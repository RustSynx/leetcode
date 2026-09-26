//
// Created by Milo on 9/26/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  string evaluate(string s, vector<vector<string>>& knowledge) {
    int n = s.length();
    unordered_map<string, string> map;
    for (const auto& v : knowledge) {
      map[v[0]] = v[1];
    }
    string result;
    for (int i = 0; i < n; i++) {
      if (s[i] == '(') {
        for (int j = i + 1; j < n; j++) {
          if (s[j] == ')') {
            string key = s.substr(i + 1, j - i - 1);
            if (map.contains(key)) {
              result += map[key];
            } else {
              result += "?";
            }
            i = j;
            break;
          }
        }
      } else {
        result += s[i];
      }
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<vector<string>> knowledge = {{"name", "bob"}, {"age", "two"}};
  string result = sol.evaluate("(name)is(age)yearsold", knowledge);
  string result_expected = "bobistwoyearsold";
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  knowledge = {{"a", "b"}};
  result = sol.evaluate("hi(name)", knowledge);
  result_expected = "hi?";
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  knowledge = {{"a", "yes"}};
  result = sol.evaluate("(a)(a)(a)aaa", knowledge);
  result_expected = "yesyesyesaaa";
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}