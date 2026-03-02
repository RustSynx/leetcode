//
// Created by Milo on 3/2/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

class Solution {
 public:
  int minSwaps(vector<vector<int>>& grid) {
    int array_size = static_cast<int>(grid.size());
    vector<int> cache_zero_count(array_size, 0);
    for (int i = 0; i < array_size; i++) {
      for (int j = array_size - 1; j >= 0; j--) {
        if (grid[i][j] == 0)
          cache_zero_count[i]++;
        else
          break;
      }
    }
    int steps = 0;
    for (int current_row = 0; current_row < array_size; current_row++) {
      int found_index = -1;
      int target_count = array_size - 1 - current_row;

      for (int i = current_row; i < array_size; i++) {
        if (cache_zero_count[i] >= target_count) {
          found_index = i;
          break;
        }
      }

      if (found_index == -1) return -1;

      for (int i = found_index; i > current_row; i--) {
        swap(cache_zero_count[i], cache_zero_count[i-1]);
        steps++;
      }
    }
    return steps;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<vector<int>> input = {{0, 0, 1}, {1, 1, 0}, {1, 0, 0}};
  int result = sol.minSwaps(input);
  int result_expected = 3;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  input = {{0, 1, 1, 0}, {0, 1, 1, 0}, {0, 1, 1, 0}, {0, 1, 1, 0}};
  result = sol.minSwaps(input);
  result_expected = -1;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  input = {{1, 0, 0}, {1, 1, 0}, {1, 1, 1}};
  result = sol.minSwaps(input);
  result_expected = 0;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}