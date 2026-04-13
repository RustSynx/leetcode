//
// Created by Milo on 4/12/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

class Solution {
 public:
  string letters;
  int memo[301][27][27];
  int minimumDistance(string word) {
    letters = word;
    memset(memo, -1, sizeof(memo));
    int current_idx = 0;
    int finger2_idx = 26;
    char char_idx = word[current_idx] - 'A';
    return findDistance(current_idx + 1, char_idx, finger2_idx);
  }
  int findDistance(int current_idx, int finger1_idx, int finger2_idx) {
    if (current_idx >= letters.length()) return 0;
    if (memo[current_idx][finger1_idx][finger2_idx] != -1) {
      return memo[current_idx][finger1_idx][finger2_idx];
    }
    char char_idx = letters[current_idx] - 'A';
    int first_distance = abs((char_idx / 6) - (finger1_idx / 6)) +
                         abs((char_idx % 6) - (finger1_idx % 6));
    int second_distance = finger2_idx == 26
                              ? 0
                              : abs((char_idx / 6) - (finger2_idx / 6)) +
                                    abs((char_idx % 6) - (finger2_idx % 6));
    first_distance += findDistance(current_idx + 1, char_idx, finger2_idx);
    second_distance += findDistance(current_idx + 1, finger1_idx, char_idx);
    return memo[current_idx][finger1_idx][finger2_idx] = min(first_distance, second_distance);
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  int result = sol.minimumDistance("CAKE");
  int result_expected = 3;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.minimumDistance("HAPPY");
  result_expected = 6;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}