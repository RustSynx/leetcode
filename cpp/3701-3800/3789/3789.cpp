//
// Created by Milo on 11/11/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

class Solution {
public:
  long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
    long long temp_both = min((long long) costBoth, (long long) cost1 + cost2);
    if (need1 == need2) {
      return need1 * temp_both;
    }
    if (need1 > need2) {
      long long rest = need1 - need2;
      if (rest * temp_both > rest * cost1) {
        return need2 * temp_both + rest * cost1;
      }
      return need1 * temp_both;
    } else {
      long long rest = need2 - need1;
      if (rest * temp_both > rest * cost2) {
        return need1 * temp_both + rest * cost2;
      }
      return need2 * temp_both;
    }
    return 0;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  int result = sol.minimumCost(3, 2, 1, 3, 2);
  int result_expected = 3;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.minimumCost(5, 4, 15, 2, 3);
  result_expected = 22;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  result = sol.minimumCost(5, 4, 15, 0, 0);
  result_expected = 0;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}