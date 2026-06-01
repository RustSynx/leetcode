//
// Created by Milo on 6/1/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int minimumCost(vector<int>& cost) {
    int n = static_cast<int>(cost.size());
    ranges::sort(cost);
    int result = 0;
    for (int i = n - 1; i >= 0; i--) {
      if ((n - i) % 3 == 0) continue;
      result += cost[i];
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> cost = {1, 2, 3};
  int result = sol.minimumCost(cost);
  int result_expected = 5;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  cost = {6, 5, 7, 9, 2, 2};
  result = sol.minimumCost(cost);
  result_expected = 23;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  cost = {5, 5};
  result = sol.minimumCost(cost);
  result_expected = 10;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}