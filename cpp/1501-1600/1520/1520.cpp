//
// Created by Milo on 9/18/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<string> maxNumOfSubstrings(string s) {
    int n = s.length();
    vector<pair<int, int>> letter_s_e(26, {-1, -1});
    for (int i = 0; i < n; i++) {
      if (letter_s_e[s[i] - 'a'].first == -1) {
        letter_s_e[s[i] - 'a'].first = i;
      }
      letter_s_e[s[i] - 'a'].second = i;
    }
    vector<pair<int, int>> intervals;
    for (auto [start, end] : letter_s_e) {
      if (start == -1) continue;
      int right = end;
      for (int i = start + 1; i <= right; i++) {
        if (letter_s_e[s[i] - 'a'].second > right) {
          right = letter_s_e[s[i] - 'a'].second;
        }
        if (letter_s_e[s[i] - 'a'].first < start) {
          right = -1;
          break;
        }
      }
      if (right != -1) intervals.push_back({start, right});
    }
    ranges::sort(intervals, [](pair<int, int>& a, pair<int, int>& b) {
      return a.second < b.second;
    });
    int right = -1;
    vector<string> result;
    for (auto& [start, end] : intervals) {
      if (start > right) {
        result.push_back(s.substr(start, end - start + 1));
        right = end;
      }
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<string> result = sol.maxNumOfSubstrings("adefaddaccc");
  vector<string> result_expected = {"e", "f", "ccc"};
  cout << "result : ";
  for (string s : result) {
    cout << s << " ";
  }
  cout << endl;
  cout << "result_expected : ";
  for (string s : result_expected) {
    cout << s << " ";
  }
  cout << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.maxNumOfSubstrings("abbaccd");
  result_expected = {"bb", "cc", "d"};
  cout << "result : ";
  for (string s : result) {
    cout << s << " ";
  }
  cout << endl;
  cout << "result_expected : ";
  for (string s : result_expected) {
    cout << s << " ";
  }
  cout << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}