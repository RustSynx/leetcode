//
// Created by Milo on 3/8/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

class Solution {
public:
  int minimumIndex(vector<int>& capacity, int itemSize) {
    int result = INT_MAX;
    int current_box_size = INT_MAX;
    for (int i = 0; i < capacity.size(); i++) {
      if (capacity[i] >= itemSize && current_box_size > capacity[i]) {
        current_box_size = capacity[i];
        result = i;
      }
    }
    if (result == INT_MAX) return -1;
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> input = {1, 5, 3, 7};
  int result = sol.minimumIndex(input, 3);
  int result_expected = 2;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  input = {3, 5, 4, 3};
  result = sol.minimumIndex(input, 2);
  result_expected = 0;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  input = {4};
  result = sol.minimumIndex(input, 5);
  result_expected = -1;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}