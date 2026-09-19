//
// Created by Milo on 9/19/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

class Solution {
 public:
  bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1,
                    int x2, int y2) {
    int closest_x = max(x1, min(xCenter, x2));
    int closest_y = max(y1, min(yCenter, y2));
    int dist_x = xCenter - closest_x;
    int dist_y = yCenter - closest_y;
    return (dist_x * dist_x + dist_y * dist_y) <= radius * radius;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  int result = sol.checkOverlap(1, 0, 0, 1, -1, 3, 1);
  int result_expected = true;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.checkOverlap(1, 1, 1, 1, -3, 2, -1);
  result_expected = false;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  result = sol.checkOverlap(1, 0, 0, -1, 0, 0, 1);
  result_expected = true;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}