//
// Created by Milo on 8/9/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int n;
  int stoneGameII(vector<int>& piles) {
    n = piles.size();
    vector<int> suffix_sum(n + 1);
    for (int i = n; i > 0; i--) {
      suffix_sum[i - 1] = suffix_sum[i] + piles[i - 1];
    }
    vector<vector<int>> memo(n, vector<int>(n + 1, -1));
    return dp(suffix_sum, memo, 0, 1);
  }
  int dp(vector<int>& suffix_sum, vector<vector<int>>& memo, int start, int M) {
    if (start >= n) return 0;
    if (start + 2 * M >= n) return suffix_sum[start];
    if (memo[start][M] != -1) return memo[start][M];
    int result = 0;
    for (int X = 1; X <= 2 * M && start + X <= n; X++) {
      result = max(result, suffix_sum[start] -
                               dp(suffix_sum, memo, start + X, max(X, M)));
    }
    return memo[start][M] = result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> piles = {2, 7, 9, 4, 4};
  int result = sol.stoneGameII(piles);
  int result_expected = 10;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  piles = {1, 2, 3, 4, 5, 100};
  result = sol.stoneGameII(piles);
  result_expected = 104;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}