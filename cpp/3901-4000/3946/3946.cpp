//
// Created by Milo on 11/27/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maximumSaleItems(vector<vector<int>>& items, int budget) {
    int n = items.size();
    vector<int> val(n);
    int min_v = INT_MAX;
    for (int i = 0; i < n; i++) {
      int factor = items[i][0];
      int free_sum = 0;
      for (int j = 0; j < n; j++) {
        if (i == j) continue;
        if (items[j][0] % factor == 0) free_sum++;
      }
      val[i] = free_sum + 1;
      min_v = min(min_v, items[i][1]);
    }
    vector<int> dp(budget + 1);
    for (int i = 0; i < n; i++) {
      int price = items[i][1];
      for (int j = budget; j >= price; j--) {
        dp[j] = max(dp[j], dp[j - price] + val[i]);
      }
    }
    int result = 0;
    for (int i = 0; i <= budget; i++) {
      int extra = (budget - i) / min_v;
      result = max(result, dp[i] + extra);
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<vector<int>> items = {{6, 2}, {2, 6}, {3, 4}};
  int result = sol.maximumSaleItems(items, 9);
  int result_expected = 4;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  items = {{2, 4}, {3, 2}, {4, 1}, {6, 4}, {12, 4}};
  result = sol.maximumSaleItems(items, 8);
  result_expected = 10;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}