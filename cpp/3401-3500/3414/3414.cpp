//
// Created by Milo on 9/12/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

struct Interval {
  int start, end, weight, idx;
};

struct Dp {
  long long weight;
  vector<int> indices;
};

class Solution {
 public:
  vector<int> maximumWeight(vector<vector<int>>& intervals) {
    int n = intervals.size();
    vector<Interval> n_intervals;
    n_intervals.reserve(n);
    for (int i = 0; i < n; i++) {
      n_intervals.push_back(
          {intervals[i][0], intervals[i][1], intervals[i][2], i});
    }
    ranges::sort(n_intervals, [](const Interval& a, const Interval& b) {
      return a.start < b.start;
    });
    vector<vector<Dp>> dp(n + 1, vector<Dp>(5));
    for (int i = n - 1; i >= 0; i--) {
      auto next_idx =
          lower_bound(
              n_intervals.begin(), n_intervals.end(), n_intervals[i].end + 1,
              [](const Interval& a, int value) { return a.start < value; }) -
          n_intervals.begin();
      for (int j = 1; j <= 4; j++) {
        long long skip_weight = dp[i + 1][j].weight;
        vector<int> skip_indices = dp[i + 1][j].indices;
        long long take_weight = n_intervals[i].weight + dp[next_idx][j - 1].weight;
        vector<int> take_indices = dp[next_idx][j - 1].indices;
        take_indices.push_back(n_intervals[i].idx);
        ranges::sort(take_indices);
        if (take_weight > skip_weight) {
          dp[i][j] = {take_weight, take_indices};
        } else if (take_weight < skip_weight) {
          dp[i][j] = {skip_weight, skip_indices};
        } else {
          if (take_indices < skip_indices) {
            dp[i][j] = {take_weight, take_indices};
          } else {
            dp[i][j] = {skip_weight, skip_indices};
          }
        }
      }
    }
    return dp[0][4].indices;
  }
};

int main() {
  Solution sol;
  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<vector<int>> intervals = {{1, 3, 2}, {4, 5, 2}, {1, 5, 5},
                                   {6, 9, 3}, {6, 7, 1}, {8, 9, 1}};
  vector<int> result = sol.maximumWeight(intervals);
  vector<int> result_expected = {2, 3};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  intervals = {{5, 8, 1}, {6, 7, 7},   {4, 7, 3}, {9, 10, 6},
               {7, 8, 2}, {11, 14, 3}, {3, 5, 5}};
  result = sol.maximumWeight(intervals);
  result_expected = {1, 3, 5, 6};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}