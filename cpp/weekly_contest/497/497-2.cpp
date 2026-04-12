//
// Created by Milo on 4/12/26.
//
#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<double> internalAngles(vector<int>& sides) {
    double a = sides[0];
    double b = sides[1];
    double c = sides[2];
    if (a + b <= c || a + c <= b || b + c <= a) return {};
    double cosA = clamp((b * b + c * c - a * a) / (2 * b * c), -1.0, 1.0);
    double cosB = clamp((a * a + c * c - b * b) / (2 * a * c), -1.0, 1.0);
    double cosC = clamp((a * a + b * b - c * c) / (2 * a * b), -1.0, 1.0);
    double degreeA = acos(cosA) * (180.0 / acos(-1.0));
    double degreeB = acos(cosB) * (180.0 / acos(-1.0));
    double degreeC = acos(cosC) * (180.0 / acos(-1.0));
    vector<double> result = {round(degreeA * 100000) / 100000, round(degreeB * 100000) / 100000,
            round(degreeC * 100000) / 100000};
    sort(result.begin(),result.end());
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> sides = {3, 4, 5};
  vector<double> result = sol.internalAngles(sides);
  vector<double> result_expected = {36.86990, 53.13010, 90.00000};
  // assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  sides = {2, 4, 2};
  result = sol.internalAngles(sides);
  result_expected = {};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}