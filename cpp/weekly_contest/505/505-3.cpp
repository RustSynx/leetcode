//
// Created by Milo on 6/7/26.
//
#include <cassert>
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
  long long maximumSum(vector<int>& nums, int m, int l, int r) {
    int n = static_cast<int>(nums.size());
    vector<long long> prefix_sum(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      prefix_sum[i] = prefix_sum[i - 1] + nums[i - 1];
    }
    vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, LONG_MIN));
    for (int i = 0; i <= n; i++) {
      dp[i][0] = 0;
    }

    for (int j = 1; j <= m; j++) {
      deque<int> dq;

      for (int i = 1; i <= n; i++) {
        dp[i][j] = dp[i - 1][j];
        int curr_p = i - l;

        if (curr_p >= 0 && dp[curr_p][j - 1] != LONG_MIN) {
          long long val = dp[curr_p][j - 1] - prefix_sum[curr_p];

          while (!dq.empty()) {
            int back_idx = dq.back();
            long long back_val = dp[back_idx][j - 1] - prefix_sum[back_idx];
            if (back_val <= val) {
              dq.pop_back();
            } else {
              break;
            }
          }
          dq.push_back(curr_p);
        }
        while (!dq.empty() && dq.front() < i - r) {
          dq.pop_front();
        }
        if (!dq.empty()) {
          int best_p = dq.front();
          long long best_val = dp[best_p][j - 1] - prefix_sum[best_p];
          dp[i][j] = max(dp[i][j], prefix_sum[i] + best_val);
        }
      }
    }

    long long result = LONG_MIN;
    for (int i = 1; i <= m; i++) {
      result = max(result, dp[n][i]);
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> nums = {4, 1, -5, 2};
  long long result = sol.maximumSum(nums, 2, 1, 3);
  long long result_expected = 7;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums = {1, 0, 3, 4};
  result = sol.maximumSum(nums, 2, 1, 2);
  result_expected = 8;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  nums = {-1, 7, -4};
  result = sol.maximumSum(nums, 1, 2, 3);
  result_expected = 6;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 4
  cout << "Test Case 4: " << endl;
  nums = {-3, -4, -1};
  result = sol.maximumSum(nums, 2, 1, 2);
  result_expected = -1;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}

