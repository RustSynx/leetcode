//
// Created by Milo on 6/23/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
      int mod = 1e9 + 7;
      int max_num = r - l + 1;
      vector prev_prefix_sum(max_num + 1, vector<int>(2));
      vector curr_prefix_sum(max_num + 1, vector<int>(2));

      for (int i = 1; i <= max_num; i++) {
        prev_prefix_sum[i][0] = prev_prefix_sum[i - 1][0] + 1;
        prev_prefix_sum[i][1] = prev_prefix_sum[i - 1][1] + 1;
      }

      for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= max_num; j++) {
          int increase = prev_prefix_sum[j - 1][0];
          int decrease = (prev_prefix_sum[max_num][1] - prev_prefix_sum[j][1] + mod) % mod;

          curr_prefix_sum[j][0] = (curr_prefix_sum[j - 1][0] + decrease) % mod;
          curr_prefix_sum[j][1] = (curr_prefix_sum[j - 1][1] + increase) % mod;
        }
        prev_prefix_sum = curr_prefix_sum;
      }

      int result = 0;
      result = (result + prev_prefix_sum[max_num][0]) % mod;
      result = (result + prev_prefix_sum[max_num][1]) % mod;

      return result;
    }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  int result = sol.zigZagArrays(3, 4, 5);
  int result_expected = 2;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.zigZagArrays(3, 1, 3);
  result_expected = 10;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}