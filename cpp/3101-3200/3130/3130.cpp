//
// Created by Milo on 3/10/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  int mod = 1e9 + 7;

 public:
  int numberOfStableArrays(int zero, int one, int limit) {
    vector<vector<vector<int>>> memo(
        zero + 1, vector<vector<int>>(one + 1, vector<int>(2, -1)));

    return (calculateArrays(zero, one, limit, 0, memo) +
            calculateArrays(zero, one, limit, 1, memo)) %
           mod;
  }

  int calculateArrays(int zero, int one, int limit, int last_number,
                      vector<vector<vector<int>>>& memo) {
    if (zero < 0 || one < 0) return 0;

    if (zero == 0) {
      if (last_number == 0) return 0;
      return (one <= limit) ? 1 : 0;
    }

    if (one == 0) {
      if (last_number == 1) return 0;
      return (zero <= limit) ? 1 : 0;
    }

    if (memo[zero][one][last_number] != -1) return memo[zero][one][last_number];

    long long temp = 0;

    if (last_number == 1) {
      temp = (calculateArrays(zero, one - 1, limit, 0, memo) +
              calculateArrays(zero, one - 1, limit, 1, memo)) %
             mod;
      if (one > limit)
        temp =
            (temp - calculateArrays(zero, one - (limit + 1), limit, 0, memo) +
             mod) %
            mod;
      memo[zero][one][last_number] = (temp % mod + mod) % mod;
    }
    if (last_number == 0) {
      temp = (calculateArrays(zero - 1, one, limit, 0, memo) +
              calculateArrays(zero - 1, one, limit, 1, memo)) %
             mod;
      if (zero > limit)
        temp =
            (temp - calculateArrays(zero - (limit + 1), one, limit, 1, memo) +
             mod) %
            mod;
    }
    memo[zero][one][last_number] = static_cast<int>(temp);
    return memo[zero][one][last_number];
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  int result = sol.numberOfStableArrays(1, 1, 2);
  int result_expected = 2;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.numberOfStableArrays(1, 2, 1);
  result_expected = 1;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  result = sol.numberOfStableArrays(3, 3, 2);
  result_expected = 14;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}