//
// Created by Milo on 7/31/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
      vector<int> word_count(26);
      for (char c : word) {
        word_count[c - 'a']++;
      }
      ranges::sort(word_count, greater<int>());
      int result = 0;
      int weight = 1;
      for (int i = 0; i < word_count.size(); i++) {
        if (word_count[i] == 0) continue;
        result += weight * word_count[i];
        if ((i + 1) % 8 == 0) weight++;
      }
      return result;
    }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  int result = sol.minimumPushes("abcde");
  int result_expected = 5;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.minimumPushes("xyzxyzxyzxyz");
  result_expected = 12;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  result = sol.minimumPushes("aabbccddeeffgghhiiiiii");
  result_expected = 24;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}