//
// Created by Milo on 8/16/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  bool stoneGameIX(vector<int>& stones) {
    int n = stones.size();
    int count[3] = {};
    for (int i = 0; i < n; i++) {
      count[stones[i] % 3]++;
    }
    if (count[0] % 2 == 0) {
      return count[1] > 0 && count[2] > 0;
    }
    return abs(count[2] - count[1]) > 2;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> stones = {2, 1};
  bool result = sol.stoneGameIX(stones);
  bool result_expected = true;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  stones = {2};
  result = sol.stoneGameIX(stones);
  result_expected = false;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  stones = {5, 1, 2, 4, 3};
  result = sol.stoneGameIX(stones);
  result_expected = false;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}