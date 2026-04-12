//
// Created by Milo on 4/11/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

class Solution {
public:
  string trafficSignal(int timer) {
    if (timer == 0) {
      return "Green";
    }
    if (timer == 30) {
      return "Orange";
    }
    if (30 < timer && timer <= 90) {
      return "Red";
    }
    return "Invalid";
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  string result = sol.trafficSignal(60);
  string result_expected = "Red";
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.trafficSignal(5);
  result_expected = "Invalid";
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}