//
// Created by Milo on 6/13/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  string mapWordWeights(vector<string>& words, vector<int>& weights) {
    string result;
    result.reserve(words.size());
    for (const string& word : words) {
      int sum = 0;
      for (char c : word) {
        sum += weights[c - 'a'];
      }
      result += 'z' - (sum % 26);
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<string> words = {"abcd", "def", "xyz"};
  vector<int> weights = {5, 3, 12, 14, 1, 2, 3, 2, 10, 6, 6, 9, 7,
                         8, 7, 10, 8,  9, 6, 9, 9, 8,  3, 7, 7, 2};
  string result = sol.mapWordWeights(words, weights);
  string result_expected = "rij";
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  words = {"a", "b", "c"};
  weights = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
             1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  result = sol.mapWordWeights(words, weights);
  result_expected = "yyy";
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  words = {"abcd"};
  weights = {7, 5, 3,  4, 3, 5, 4, 9, 4, 2, 2, 7, 10,
             2, 5, 10, 6, 1, 2, 2, 4, 1, 3, 4, 4, 5};
  result = sol.mapWordWeights(words, weights);
  result_expected = "g";
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}