//
// Created by Milo on 9/14/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
    bool x_overlap = rec1[0] < rec2[2] && rec2[0] < rec1[2];
    bool y_overlap = rec1[1] < rec2[3] && rec2[1] < rec1[3];
    return x_overlap && y_overlap;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> rec1 = {0, 0, 2, 2};
  vector<int> rec2 = {1, 1, 3, 3};
  bool result = sol.isRectangleOverlap(rec1, rec2);
  bool result_expected = true;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  rec1 = {0, 0, 1, 1};
  rec2 = {1, 0, 2, 1};
  result = sol.isRectangleOverlap(rec1, rec2);
  result_expected = false;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  rec1 = {0, 0, 1, 1};
  rec2 = {2, 2, 3, 3};
  result = sol.isRectangleOverlap(rec1, rec2);
  result_expected = false;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}