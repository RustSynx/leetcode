//
// Created by Milo on 8/17/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int stoneGameV(vector<int>& stoneValue) {
    int n = stoneValue.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    vector<int> prefix_sum(n + 1, 0);
    for (int i = 0; i < n; i++) {
      prefix_sum[i + 1] = prefix_sum[i] + stoneValue[i];
    }
    return calcStones(1, n, prefix_sum, dp);
  }
  int calcStones(int start, int end, vector<int>& prefix_sum,
                 vector<vector<int>>& dp) {
    if (start == end) return 0;
    if (dp[start][end] != -1) return dp[start][end];
    int result = 0;
    for (int i = start; i < end; i++) {
      int left_sum = prefix_sum[i] - prefix_sum[start - 1];
      int right_sum = prefix_sum[end] - prefix_sum[i];
      if (left_sum > right_sum) {
        result =
            max(result, right_sum + calcStones(i + 1, end, prefix_sum, dp));
      } else if (left_sum < right_sum) {
        result = max(result, left_sum + calcStones(start, i, prefix_sum, dp));
      } else {
        result = max({result, left_sum + calcStones(start, i, prefix_sum, dp),
                      right_sum + calcStones(i + 1, end, prefix_sum, dp)});
      }
    }
    return dp[start][end] = result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> grid = {6, 2, 3, 4, 5, 5};
  int result = sol.stoneGameV(grid);
  int result_expected = 18;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  grid = {7, 7, 7, 7, 7, 7, 7};
  result = sol.stoneGameV(grid);
  result_expected = 28;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  grid = {4};
  result = sol.stoneGameV(grid);
  result_expected = 0;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}