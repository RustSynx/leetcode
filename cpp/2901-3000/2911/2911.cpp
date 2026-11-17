//
// Created by Milo on 11/17/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumChanges(string s, int k) {
      int n = s.length();
        const int INF = 1e9;
        vector<vector<int>> divisors(n + 1);
        for (int i = 1; i < n; i++) {
            for (int j = i * 2; j <= n; j += i) {
                divisors[j].push_back(i);
            }
        }
        vector<vector<int>> cost(n, vector<int>(n, INF));
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int L = j - i + 1;
                int min_changes = INF;
                for (int d : divisors[L]) {
                    int changes = 0;
                    for (int c = 0; c < d; c++) {
                        int left = i + c;
                        int right = i + c + L - d;
                        while (left < right) {
                            if (s[left] != s[right]) {
                                changes++;
                            }
                            left += d;
                            right -= d;
                        }
                    }
                    if (changes < min_changes) {
                        min_changes = changes;
                    }
                }
                cost[i][j] = min_changes;
            }
        }
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, INF));
        dp[0][0] = 0;
        for (int i = 1; i <= k; i++) {
            for (int j = i * 2; j <= n; j++) {
                for (int prev = (i - 1) * 2; prev <= j - 2; prev++) {
                    if (dp[prev][i - 1] != INF && cost[prev][j - 1] != INF) {
                        int current_cost = dp[prev][i - 1] + cost[prev][j - 1];
                        if (current_cost < dp[j][i]) {
                            dp[j][i] = current_cost;
                        }
                    }
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
  int result = sol.minimumChanges("abcac", 2);
  int result_expected = 1;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.minimumChanges("abcdef", 2);
  result_expected = 2;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  result = sol.minimumChanges("aabbaa", 3);
  result_expected = 0;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}