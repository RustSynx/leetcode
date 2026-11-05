//
// Created by Milo on 11/05/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

struct Group {
  int x;
  vector<long long> cost;
  multiset<long long> low, high;
  long long sum_low = 0, sum_high = 0;

  Group(int n, int x) : x(x) { cost.resize(n - x + 1, 0); }
  void balance() {
    int current_total_size = low.size() + high.size();
    int target_low = (current_total_size + 1) / 2;

    while (low.size() < target_low) {
      auto it = high.begin();
      low.insert(*it);
      sum_low += *it;
      sum_high -= *it;
      high.erase(it);
    }
    while (low.size() > target_low) {
      auto it = prev(low.end());
      high.insert(*it);
      sum_high += *it;
      sum_low -= *it;
      low.erase(it);
    }
  }
  void add(long long num) {
    if (low.empty() || num <= *low.rbegin()) {
      low.insert(num);
      sum_low += num;
    } else {
      high.insert(num);
      sum_high += num;
    }
    balance();
  }
  void remove(long long num) {
    auto it = high.find(num);
    if (it != high.end()) {
      high.erase(it);
      sum_high -= num;
    } else {
      it = low.find(num);
      low.erase(it);
      sum_low -= num;
    }
    balance();
  }
};

class Solution {
 public:
  long long INF = 1e18;
  long long minOperations(vector<int>& nums, int x, int k) {
    int n = nums.size();
    Group g(n, x);
    for (int i = 0; i < x; i++) {
      g.add(nums[i]);
    }
    for (int i = 0; i <= n - x; i++) {
      long long median = *g.low.rbegin();
      long long cost_low = (long long)g.low.size() * median - g.sum_low;
      long long cost_high = g.sum_high - (long long)g.high.size() * median;
      g.cost[i] = cost_low + cost_high;
      if (i + x < n) {
        g.add(nums[i + x]);
        g.remove(nums[i]);
      }
    }
    vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, INF));
    for (int i = 0; i <= n; i++) {
      dp[i][0] = 0;
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= k; j++) {
        dp[i][j] = dp[i - 1][j];
        if (i >= x) {
          dp[i][j] = min(dp[i][j], dp[i - x][j - 1] + g.cost[i - x]);
        }
      }
    }
    return dp[n][k];
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> nums = {5, -2, 1, 3, 7, 3, 6, 4, -1};
  int result = sol.minOperations(nums, 3, 2);
  int result_expected = 8;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums = {9, -2, -2, -2, 1, 5};
  result = sol.minOperations(nums, 2, 2);
  result_expected = 3;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}