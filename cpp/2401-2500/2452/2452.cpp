//
// Created by Milo on 4/22/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
    int n = static_cast<int>(dictionary.size());
    vector<string> result;
    result.reserve(queries.size());
    for (const string& query : queries) {
      for (int i = 0; i < n; i++) {
        int diff = 0;
        string& dic = dictionary[i];
        for (int j = 0; j < dic.size(); j++) {
          if (diff > 2) break;
          if (query[j] != dic[j]) diff++;
        }
        if (diff <= 2) {
          result.push_back(query);
          break;
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
  vector<string> queries = {"word","note","ants","wood"};
  vector<string> dictionary = {"wood","joke","moat"};
  vector<string> result = sol.twoEditWords(queries, dictionary);
  vector<string> result_expected = {"word","note","wood"};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  queries = {"yes"};
  dictionary = {"not"};
  result = sol.twoEditWords(queries, dictionary);
  result_expected = {};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}