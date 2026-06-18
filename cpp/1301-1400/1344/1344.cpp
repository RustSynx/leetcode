//
// Created by Milo on 6/18/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

class Solution {
public:
  double angleClock(int hour, int minutes) {
    double hour_angle = hour * 30 + minutes * 0.5;
    double min_angle = minutes * 6;
    double between_angle = hour_angle > min_angle ? hour_angle - min_angle : min_angle - hour_angle;
    return between_angle > 180 ? 360 - between_angle : between_angle;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  double result = sol.angleClock(12, 30);
  double result_expected = 165;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.angleClock(3, 30);
  result_expected = 75;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  result = sol.angleClock(3, 15);
  result_expected = 7.5;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}