//
// Created by Milo on 5/28/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  struct SuffixNode {
    int children[26];
    int min_idx;

    SuffixNode(int idx) : min_idx(idx) {
      for (int i = 0; i < 26; i++) {
        children[i] = -1;
      }
    }
  };

 public:
  vector<int> stringIndices(vector<string>& wordsContainer,
                            vector<string>& wordsQuery) {
    int n = static_cast<int>(wordsContainer.size());
    int word_len = INT_MAX;
    int global_min_idx = INT_MAX;
    for (int i = 0; i < n; i++) {
      if (word_len > wordsContainer[i].length()) {
        word_len = wordsContainer[i].length();
        global_min_idx = i;
      }
    }
    vector<SuffixNode> suffix_vec;
    suffix_vec.reserve(500001);
    suffix_vec.emplace_back(global_min_idx);
    for (int i = 0; i < n; i++) {
      int curr_node = 0;
      int curr_len = wordsContainer[i].length();

      for (int j = curr_len - 1; j >= 0; j--) {
        int char_i = wordsContainer[i][j] - 'a';
        int vec_size = static_cast<int>(suffix_vec.size());
        if (suffix_vec[curr_node].children[char_i] == -1) {
          suffix_vec[curr_node].children[char_i] = vec_size;
          suffix_vec.emplace_back(i);
        }
        curr_node = suffix_vec[curr_node].children[char_i];
        int min_idx_len = wordsContainer[suffix_vec[curr_node].min_idx].length();
        if (min_idx_len > curr_len ||
            (min_idx_len == curr_len && i < suffix_vec[curr_node].min_idx)) {
          suffix_vec[curr_node].min_idx = i;
        }
      }
    }
    vector<int> result;
    result.reserve(wordsQuery.size());
    for (string& query : wordsQuery) {
      int curr_node = 0;
      for (int j = query.length() - 1; j >= 0; j--) {
        int char_i = query[j] - 'a';
        if (suffix_vec[curr_node].children[char_i] == -1) {
          break;
        }
        curr_node = suffix_vec[curr_node].children[char_i];
      }
      result.push_back(suffix_vec[curr_node].min_idx);
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<string> wordsContainer = {"abcd", "bcd", "xbcd"};
  vector<string> wordsQuery = {"cd", "bcd", "xyz"};
  vector<int> result = sol.stringIndices(wordsContainer, wordsQuery);
  vector<int> result_expected = {1, 1, 1};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  wordsContainer = {"abcdefgh", "poiuygh", "ghghgh"};
  wordsQuery = {"gh", "acbfgh", "acbfegh"};
  result = sol.stringIndices(wordsContainer, wordsQuery);
  result_expected = {2, 0, 2};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}