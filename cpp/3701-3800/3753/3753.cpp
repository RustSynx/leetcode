//
// Created by Milo on 6/5/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  pair<long long, long long> memo[11][11][2][2][16];
  long long totalWaviness(long long num1, long long num2) {
    fill(&memo[0][0][0][0][0], &memo[0][0][0][0][0] + (11 * 11 * 2 * 2 * 16), make_pair(-1LL, -1LL));
    long long num2_sum = dp(num2, 0, 10, 10, true, true).second;
    fill(&memo[0][0][0][0][0], &memo[0][0][0][0][0] + (11 * 11 * 2 * 2 * 16), make_pair(-1LL, -1LL));
    long long num1_sum = dp(num1 - 1, 0, 10, 10, true, true).second;
    return num2_sum - num1_sum;

  }
  pair<long long, long long> dp(long long num, int idx, int prev1, int prev2, bool leading_zero,
               bool boundary) {
    string num_str = to_string(num);

    if (idx == num_str.length()) return make_pair(1, 0);

    if (memo[prev1][prev2][leading_zero][boundary][idx].second != -1) {
      return memo[prev1][prev2][leading_zero][boundary][idx];
    }

    int max_num = 9;
    if (boundary) {
      max_num = num_str[idx] - '0';
    }
    long long sum = 0;
    long long total_count = 0;
    for (int i = 0; i <= max_num; i++) {
      bool next_leading_zero = leading_zero && i == 0;
      bool next_boundary = boundary && i == max_num;

      int count = 0;
      if (!next_leading_zero && prev1 != 10 && prev2 != 10) {
        if (prev1 > prev2 && i > prev2) count = 1;
        if (prev1 < prev2 && i < prev2) count = 1;
      }

      int next1 = 10;
      int next2 = 10;
      if (!next_leading_zero) {
        next1 = prev2;
        next2 = i;
      }
      auto [next_count, next_sum] = dp(num, idx + 1, next1, next2, next_leading_zero, next_boundary);
      total_count += next_count;
      sum += next_sum + (count * next_count);
    }
    return memo[prev1][prev2][leading_zero][boundary][idx] = make_pair(total_count, sum);
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  int num1 = 120;
  int num2 = 130;
  int result = sol.totalWaviness(num1, num2);
  int result_expected = 3;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  num1 = 198;
  num2 = 202;
  result = sol.totalWaviness(num1, num2);
  result_expected = 3;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  num1 = 4848;
  num2 = 4848;
  result = sol.totalWaviness(num1, num2);
  result_expected = 2;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}