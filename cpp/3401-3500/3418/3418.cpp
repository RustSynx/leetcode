//
// Created by Milo on 4/2/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<vector<int>>> memo;
  int m, n;

  int maximumAmount(vector<vector<int>>& coins) {
    m = static_cast<int>(coins.size());
    n = static_cast<int>(coins[0].size());
    memo.clear();
    memo.resize(m, vector<vector<int>>(n, vector<int>(3, INT_MIN)));
    return calcCoin(coins, 0, 0, 2);
  }

  int calcCoin(vector<vector<int>>& coins, int i, int j, int neutral) {
    if (i >= m || j >= n) return INT_MIN;
    if (m - 1 == i && n - 1 == j) {
      if (coins[i][j] >= 0) return coins[i][j];
      return neutral > 0 ? 0 : coins[i][j];
    }
    if (memo[i][j][neutral] != INT_MIN) return memo[i][j][neutral];

    int next_value = max(calcCoin(coins, i, j + 1, neutral), calcCoin(coins, i + 1, j, neutral));

    int result = 0;
    if (coins[i][j] >= 0) {
      result = coins[i][j] + next_value;
    } else {
      int use_neutral = INT_MIN;
      int not_use = coins[i][j] + next_value;
      if (neutral > 0) {
        use_neutral = max(calcCoin(coins, i + 1, j, neutral - 1), calcCoin(coins, i, j + 1, neutral - 1));
      }
      result = max(use_neutral, not_use);
    }
    return memo[i][j][neutral] = result;
  }
};

int main() {
  Solution sol;
  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<vector<int>> input = {{0,1,-1},{1,-2,3},{2,-3,4}};
  int result = sol.maximumAmount(input);
  int result_expected = 8;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  input = {{10,10,10},{10,10,10}};
  result = sol.maximumAmount(input);
  result_expected = 40;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}