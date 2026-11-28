//
// Created by Milo on 11/28/26.
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
    vector<int> cnt(n + 1);
    int max_f = 0;
    int min_v = INT_MAX;
    for (int i = 0; i < n; i++) {
      cnt[items[i][0]]++;
      max_f = max(max_f, items[i][0]);
      min_v = min(min_v, items[i][1]);
    }
    vector<int> bonus(max_f + 1);
    for (int i = 1; i <= max_f; i++) {
      if (cnt[i] == 0) continue;
      for (int j = i; j <= max_f; j += i) {
        bonus[i] += cnt[j];
      }
      bonus[i]--;
    }
    vector<pair<int, int>> deals;
    for (int i = 0; i < n; i++) {
      int f = items[i][0];
      int p = items[i][1];
      if (bonus[f] > 0 && p < 2 * min_v) {
        deals.push_back({p, bonus[f]});
      }
    }
    ranges::sort(deals);
    int result = 0;
    for (auto [p, b] : deals) {
      int buy = min(b, budget / p);
      if (buy == 0) break;
      budget -= buy * p;
      result += buy * 2;
    }
    result += budget / min_v;
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<vector<int>> items = {{1, 6}, {2, 4}, {3, 5}};
  int result = sol.maximumSaleItems(items, 19);
  int result_expected = 5;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  items = {{2, 8}, {1, 10}, {6, 6}, {4, 12}, {5, 20}, {5, 17}};
  result = sol.maximumSaleItems(items, 35);
  result_expected = 7;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}