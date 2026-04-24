//
// Created by Milo on 4/24/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

class Solution {
public:
  int furthestDistanceFromOrigin(string moves) {
    int result = 0;
    int under_score_cnt = 0;
    for (char c : moves) {
      if (c == 'R') {
        result++;
      }
      if (c == 'L') {
        result--;
      }
      if (c == '_') {
        under_score_cnt++;
      }
    }
    return abs(result) + under_score_cnt;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  int result = sol.furthestDistanceFromOrigin("L_RL__R");
  int result_expected = 3;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.furthestDistanceFromOrigin("_R__LL_");
  result_expected = 5;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  result = sol.furthestDistanceFromOrigin("_______");
  result_expected = 7;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}