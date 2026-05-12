//
// Created by Milo on 5/12/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int minimumEffort(vector<vector<int>>& tasks) {
    int n = static_cast<int>(tasks.size());
    sort(tasks.begin(), tasks.end(), [](const vector<int>& a, const vector<int>& b) {
      return a[1] - a[0] > b[1] - b[0];
    });
    int result = tasks[0][1];
    int curr_energy = result;
    for (int i = 0; i < n; i++) {
      if (curr_energy >= tasks[i][1]) {
        curr_energy -= tasks[i][0];
      } else {
        int diff = tasks[i][1] - curr_energy;
        curr_energy += diff;
        result += diff;
        curr_energy -= tasks[i][0];
      }
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<vector<int>> tasks = {{1, 2}, {2, 4}, {4, 8}};
  int result = sol.minimumEffort(tasks);
  int result_expected = 8;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  tasks = {{1, 3}, {2, 4}, {10, 11}, {10, 12}, {8, 9}};
  result = sol.minimumEffort(tasks);
  result_expected = 32;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  tasks = {{1, 7}, {2, 8}, {3, 9}, {4, 10}, {5, 11}, {6, 12}};
  result = sol.minimumEffort(tasks);
  result_expected = 27;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}