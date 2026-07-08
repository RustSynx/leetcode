//
// Created by Milo on 7/8/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
    int n = s.length();
    long long mod = 1e9 + 7;

    vector prefix_sum(n + 1, 0);
    vector non_zero_count(n + 1, 0);
    vector<long long> digit_vec;
    digit_vec.push_back(0);

    for (int i = 0; i < n; i++) {
      int digit = s[i] - '0';

      prefix_sum[i + 1] = prefix_sum[i] + digit;
      non_zero_count[i + 1] = non_zero_count[i];

      if (digit != 0) {
        non_zero_count[i + 1]++;
        long long next_val = (digit_vec.back() * 10 + digit) % mod;
        digit_vec.push_back(next_val);
      }
    }

    int max_len = digit_vec.size();
    vector<long long> pow10(max_len + 1, 1);
    for (int i = 1; i <= max_len; ++i) {
      pow10[i] = pow10[i - 1] * 10 % mod;
    }

    vector<int> result;
    result.reserve(queries.size());

    for (const auto& q : queries) {
      int l = q[0];
      int r = q[1];

      long long current_sum = prefix_sum[r + 1] - prefix_sum[l];

      int a = non_zero_count[l];
      int b = non_zero_count[r + 1];

      if (a == b) {
        result.push_back(0);
      } else {
        long long x = (digit_vec[b] - digit_vec[a] * pow10[b - a]) % mod;
        if (x < 0) x += mod;

        result.push_back(static_cast<int>(x * current_sum % mod));
      }
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<vector<int>> queries = {{0, 7}, {1, 3}, {4, 6}};
  vector<int> result = sol.sumAndMultiply("10203004", queries);
  vector<int> result_expected = {12340, 4, 9};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  queries = {{0, 3}, {1, 1}};
  result = sol.sumAndMultiply("1000", queries);
  result_expected = {1, 0};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  queries = {{0, 9}};
  result = sol.sumAndMultiply("9876543210", queries);
  result_expected = {444444137};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}