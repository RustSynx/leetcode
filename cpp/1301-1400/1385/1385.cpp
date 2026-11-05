//
// Created by Milo on 11/5/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
    ranges::sort(arr2);
    int result = 0;
    for (int n : arr1) {
      auto it = ranges::lower_bound(arr2, n - d);
      if (it == arr2.end() || *it > n + d) {
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
  vector<int> arr1 = {4, 5, 8};
  vector<int> arr2 = {10, 9, 1, 8};
  int result = sol.findTheDistanceValue(arr1, arr2, 2);
  int result_expected = 2;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  arr1 = {1, 4, 2, 3};
  arr2 = {-4, -3, 6, 10, 20, 30};
  result = sol.findTheDistanceValue(arr1, arr2, 3);
  result_expected = 2;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  arr1 = {2, 1, 100, 3};
  arr2 = {-5, -2, 10, -3, 7};
  result = sol.findTheDistanceValue(arr1, arr2, 6);
  result_expected = 1;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}