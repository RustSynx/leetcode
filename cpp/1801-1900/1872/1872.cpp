//
// Created by Milo on 8/24/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int stoneGameVIII(vector<int>& stones) {
    int n = stones.size();
    vector<int> prefix_sum(n);
    prefix_sum[0] = stones[0];
    for (int i = 1; i < n; i++) {
      prefix_sum[i] = prefix_sum[i - 1] + stones[i];
    }
    int result = prefix_sum[n - 1];
    for (int i = n - 2; i > 0; i--) {
      result = max(prefix_sum[i] - result, result);
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> stones = {-1, 2, -3, 4, -5};
  int result = sol.stoneGameVIII(stones);
  int result_expected = 5;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  stones = {7, -6, 5, 10, 5, -2, -6};
  result = sol.stoneGameVIII(stones);
  result_expected = 13;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 2: " << endl;
  stones = {-10, -12};
  result = sol.stoneGameVIII(stones);
  result_expected = -22;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}