//
// Created by Milo on 5/10/26.
//
#include <cassert>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
  vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
    unordered_map<string, int> word_cnt;
    string word;
    for (const string& chunk: chunks) {
      for (const char c: chunk) {
        if (c == ' ') {
          while (!word.empty() && word.back() == '-') {
            word.pop_back();
          }
          if (!word.empty()) {
            word_cnt[word] += 1;
            word.clear();
          }
        } else if (c == '-') {
          if (word.empty()) {
            continue;
          }
          if (word.back() == '-') {
            while (!word.empty() && word.back() == '-') {
              word.pop_back();
            }
            if (!word.empty()) {
              word_cnt[word] += 1;
              word.clear();
            }
          } else {
            word += c;
          }
        } else {
          word += c;
        }
      }
    }
    if (!word.empty()) {
      while (!word.empty() && word.back() == '-') {
        word.pop_back();
      }
      word_cnt[word] += 1;
    }
    for (auto [a, b] : word_cnt) {
      cout << a << " " << b << endl;
    }
    vector<int> result;
    result.reserve(queries.size());
    for (const string& query: queries) {
      result.push_back(word_cnt[query]);
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<string> chunks = {"hello wor", "ld hello"};
  vector<string> queries = {"hello", "world", "wor"};
  vector<int> result = sol.countWordOccurrences(chunks, queries);
  vector<int> result_expected = {2, 1, 0};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  chunks = {"a--b a-", "-c"};
  queries = {"a", "b", "c"};
  result = sol.countWordOccurrences(chunks, queries);
  result_expected = {2,1,1};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  chunks = {"hello"};
  queries = {"hello", "ell"};
  result = sol.countWordOccurrences(chunks, queries);
  result_expected = {1, 0};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}