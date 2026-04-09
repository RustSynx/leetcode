//
// Created by Milo on 4/9/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int mod = 1e9 + 7;
  int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
    int q_len = static_cast<int>(queries.size());
    int n_len = static_cast<int>(nums.size());
    vector<vector<int>> query_group(401);
    for (int i = 0; i < q_len; i++) {
      int start = queries[i][0];
      int end = queries[i][1];
      int step = queries[i][2];
      int value = queries[i][3];
      if (step > 400) {
        for (int idx = start; idx <= end; idx+=step) {
          nums[idx] = static_cast<int>((1LL * nums[idx] * value) % mod);
        }
      } else {
        query_group[step].push_back(i);
      }
    }
    vector<int> acc_product_sum(n_len, 1);
    for (int step = 1; step <= 400; step++) {
      if (query_group[step].empty()) continue;

      for (int q_idx : query_group[step]) {
        int start = queries[q_idx][0];
        int end = queries[q_idx][1];
        int value = queries[q_idx][3];
        acc_product_sum[start] = static_cast<int>(1LL * acc_product_sum[start] * value % mod);
        int last_idx = start + (end - start) / step * step;
        if (last_idx + step < n_len) {
          acc_product_sum[last_idx + step] = static_cast<int>(1LL * acc_product_sum[last_idx + step] * modInverse(value) % mod);
        }
      }
      for (int j = 0; j < acc_product_sum.size(); j++) {
        if (j >= step) {
          acc_product_sum[j] = static_cast<int>(1LL * acc_product_sum[j] * acc_product_sum[j-step] % mod);
        }
        nums[j] = static_cast<int>(1LL * nums[j] * acc_product_sum[j] % mod);
      }
      ranges::fill(acc_product_sum, 1);
    }
    int result = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      result = result ^ nums[i];
    }
    return result;
  }
  long long modInverse(long long a) {
    long long res = 1;
    a %= mod;
    long long b = mod - 2;
    while (b > 0) {
      if (b % 2 == 1) res = (res * a) % mod;
      a = (a * a) % mod;
      b /= 2;
    }
    return res;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> nums = {1, 1, 1};
  vector<vector<int>> queries = {{0, 2, 1, 4}};
  int result = sol.xorAfterQueries(nums, queries);
  int result_expected = 4;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums = {2, 3, 1, 5, 4};
  queries = {{1, 4, 2, 3}, {0, 2, 1, 2}};
  result = sol.xorAfterQueries(nums, queries);
  result_expected = 31;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}