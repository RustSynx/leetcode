//
// Created by Milo on 7/6/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int removeCoveredIntervals(vector<vector<int>>& intervals) {
    ranges::sort(intervals, [](const vector<int>& a, const vector<int>& b) {
      if (a[0] == b[0]) {
        return a[1] > b[1];
      }
      return a[0] < b[0];
    });
    int max_end = 0;
    int result = 0;
    for (const auto& interval: intervals) {
      int curr_end = interval[1];
      if (curr_end > max_end) {
        max_end = curr_end;
        result++;
      }
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<vector<int>> intervals = {{1, 4}, {3, 6}, {2, 8}};
  int result = sol.removeCoveredIntervals(intervals);
  int result_expected = 2;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  intervals = {{1, 4}, {2, 3}};
  result = sol.removeCoveredIntervals(intervals);
  result_expected = 1;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}