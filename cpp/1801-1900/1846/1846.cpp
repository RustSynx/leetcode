//
// Created by Milo on 6/28/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
    int n = static_cast<int>(arr.size());
    ranges::sort(arr);
    int result = arr[0] = 1;
    for (int i = 1; i < n; i++) {
      if (arr[i] - arr[i - 1] > 1) {
        arr[i] = arr[i - 1] + 1;
      }
      result = max(result, arr[i]);
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> arr = {2, 2, 1, 2, 1};
  int result = sol.maximumElementAfterDecrementingAndRearranging(arr);
  int result_expected = 2;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  arr = {100, 1, 1000};
  result = sol.maximumElementAfterDecrementingAndRearranging(arr);
  result_expected = 3;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  arr = {1, 2, 3, 4, 5};
  result = sol.maximumElementAfterDecrementingAndRearranging(arr);
  result_expected = 5;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}