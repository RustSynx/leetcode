//
// Created by Milo on 7/14/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
 public:
  int subsequencePairCount(vector<int>& nums) {
    int n = nums.size();
    int mod = 1e9 + 7;
    vector prev_dp(201, vector<long long>(201));
    vector curr_dp(201, vector<long long>(201));
    prev_dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
      int curr_num = nums[i];
      for (int seq1_gcd = 0; seq1_gcd <= 200; seq1_gcd++) {
        for (int seq2_gcd = 0; seq2_gcd <= 200; seq2_gcd++) {
          if (prev_dp[seq1_gcd][seq2_gcd] == 0) continue;
          curr_dp[gcd(seq1_gcd, curr_num)][seq2_gcd] =
              (curr_dp[gcd(seq1_gcd, curr_num)][seq2_gcd] +
               prev_dp[seq1_gcd][seq2_gcd]) %
              mod;
          curr_dp[seq1_gcd][gcd(seq2_gcd, curr_num)] =
              (curr_dp[seq1_gcd][gcd(seq2_gcd, curr_num)] +
               prev_dp[seq1_gcd][seq2_gcd]) %
              mod;
          curr_dp[seq1_gcd][seq2_gcd] =
              (curr_dp[seq1_gcd][seq2_gcd] + prev_dp[seq1_gcd][seq2_gcd]) % mod;
        }
      }
      prev_dp = curr_dp;
      curr_dp.assign(201, vector<long long>(201, 0));
    }
    long long result = 0;
    for (int i = 1; i <= 200; i++) {
      if (prev_dp[i][i] > 0) {
        result = (result + prev_dp[i][i]) % mod;
      }
    }
    return static_cast<int>(result);
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> nums = {1, 2, 3, 4};
  int result = sol.subsequencePairCount(nums);
  int result_expected = 10;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums = {10, 20, 30};
  result = sol.subsequencePairCount(nums);
  result_expected = 2;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}