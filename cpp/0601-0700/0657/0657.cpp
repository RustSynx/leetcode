//
// Created by Milo on 4/5/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

class Solution {
public:
  bool judgeCircle(string moves) {
    int char_arr[26] = {0};
    for (char move: moves) {
      char_arr[move - 'A']++;
    }
    return char_arr[11] == char_arr[17] && char_arr[20] == char_arr[3];
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  bool result = sol.judgeCircle("UD");
  bool result_expected = true;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.judgeCircle("LL");
  result_expected = false;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}