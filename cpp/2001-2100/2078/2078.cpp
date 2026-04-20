//
// Created by Milo on 4/20/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxDistance(vector<int>& colors) {
    int n = static_cast<int>(colors.size());
    int result = 0;
    for (int i = 0; i < n; i++) {
      if (colors[n - 1] != colors[i]) {
        result = max(result, n - i - 1);
        break;
      }
    }
    if (result >= n - 1) return result;
    for (int i = n - 1; i > 0; i--) {
      if (colors[0] != colors[i]) {
        result = max(result, i);
        break;
      }
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> colors = {1, 1, 1, 6, 1, 1, 1};
  int result = sol.maxDistance(colors);
  int result_expected = 3;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  colors = {1, 8, 3, 8, 3};
  result = sol.maxDistance(colors);
  result_expected = 4;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  colors = {0, 1};
  result = sol.maxDistance(colors);
  result_expected = 1;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}