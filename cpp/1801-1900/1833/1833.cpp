//
// Created by Milo on 6/21/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int maxIceCream(vector<int>& costs, int coins) {
    int max = *ranges::max_element(costs);
    vector<int> count(max + 1);
    for (int cost : costs) {
      count[cost]++;
    }
    int result = 0;
    for (int i = 1; i <= max; i++) {
      if (count[i] == 0) continue;

      int min_count = min(count[i], coins / i);

      if (min_count == 0) break;

      result += min_count;
      coins -= min_count * i;
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> costs = {1,3,2,4,1};
  int result = sol.maxIceCream(costs, 7);
  int result_expected = 4;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  costs = {10,6,8,7,7,8};
  result = sol.maxIceCream(costs, 5);
  result_expected = 0;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  costs = {1,6,3,1,2,5};
  result = sol.maxIceCream(costs, 20);
  result_expected = 6;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}