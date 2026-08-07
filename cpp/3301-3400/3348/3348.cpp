//
// Created by Milo on 8/7/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  int p2[10] = {0, 0, 1, 0, 2, 0, 1, 0, 3, 0};
  int p3[10] = {0, 0, 0, 1, 0, 0, 1, 0, 0, 2};
  int p5[10] = {0, 0, 0, 0, 0, 1, 0, 0, 0, 0};
  int p7[10] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0};

  string result;
  int n;

  string smallestNumber(string num, long long t) {
    n = num.length();
    int factors[] = {2, 3, 5, 7};
    int factor_count[10] = {0};
    for (int f : factors) {
      while (t % f == 0) {
        t /= f;
        factor_count[f]++;
      }
    }
    if (t != 1) return "-1";
    int min_len = get_min_len(factor_count[2], factor_count[3], factor_count[5],
                              factor_count[7]);
    if (min_len > n) {
      num = string(min_len, '1');
      n = num.length();
    }
    result = num;
    if (dfs(0, factor_count[2], factor_count[3], factor_count[5],
            factor_count[7], false, num)) {
      return result;
    }
    num = string(n + 1, '1');
    n = num.length();
    result = num;
    dfs(0, factor_count[2], factor_count[3], factor_count[5], factor_count[7],
        false, num);
    return result;
  }

  bool dfs(int idx, int f2, int f3, int f5, int f7, bool is_greater,
           const string& num) {
    if (get_min_len(f2, f3, f5, f7) > n - idx) {
      return false;
    }
    if (n == idx) return true;
    int start_n = is_greater ? 1 : max(1, num[idx] - '0');
    for (int i = start_n; i <= 9; i++) {
      int nf2 = max(0, f2 - p2[i]);
      int nf3 = max(0, f3 - p3[i]);
      int nf5 = max(0, f5 - p5[i]);
      int nf7 = max(0, f7 - p7[i]);

      bool next_is_greater = is_greater || (i > num[idx] - '0');
      if (dfs(idx + 1, nf2, nf3, nf5, nf7, next_is_greater, num)) {
        result[idx] = i + '0';
        return true;
      }
    }
    return false;
  }

  int get_min_len(int f2, int f3, int f5, int f7) {
    int min_23_len = INT_MAX;
    int max_six = min(f2, f3);
    for (int i = 0; i <= max_six; i++) {
      int f2_copy = f2 - i;
      int f3_copy = f3 - i;
      f2_copy = f2_copy > 0 ? (f2_copy + 2) / 3 : 0;
      f3_copy = f3_copy > 0 ? (f3_copy + 1) / 2 : 0;
      min_23_len = min(min_23_len, i + f2_copy + f3_copy);
    }
    return f5 + f7 + min_23_len;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  string result = sol.smallestNumber("1234", 256);
  string result_expected = "1488";
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.smallestNumber("12355", 50);
  result_expected = "12355";
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  result = sol.smallestNumber("11111", 26);
  result_expected = "-1";
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  result = sol.smallestNumber("78", 42);
  result_expected = "167";
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}