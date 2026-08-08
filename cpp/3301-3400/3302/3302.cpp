//
// Created by Milo on 8/8/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> validSequence(string word1, string word2) {
    int n1 = word1.length();
    int n2 = word2.length();
    vector<int> word2_last_idx(n2, -1);
    int j = n1 - 1;
    for (int i = n2 - 1; i >= 0; i--) {
      for (; j >= 0; j--) {
        if (word1[j] == word2[i]) {
          word2_last_idx[i] = j;
          j--;
          break;
        }
      }
    }
    vector<int> result;
    bool changed = false;
    int word2_idx = 0;
    for (int i = 0; i < n1; i++) {
      if (word2_idx == n2) break;
      if (word1[i] == word2[word2_idx]) {
        result.push_back(i);
        word2_idx++;
      } else if (!changed) {
        if (word2_idx == n2 - 1 || word2_last_idx[word2_idx + 1] > i) {
          changed = true;
          result.push_back(i);
          word2_idx++;
        }
      }
    }
    if (result.size() == n2) return result;
    return {};
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> result = sol.validSequence("vbcca", "abc");
  vector<int> result_expected = {0, 1, 2};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.validSequence("bacdc", "abc");
  result_expected = {1, 2, 4};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  result = sol.validSequence("aaaaaa", "aaabc");
  result_expected = {};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 4
  cout << "Test Case 4: " << endl;
  result = sol.validSequence("abc", "ab");
  result_expected = {0, 1};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}