//
// Created by Milo on 8/21/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
 public:
  long long findKthSmallest(vector<int>& coins, int k) {
    long long left = *min_element(coins.begin(), coins.end());
    long long right = left * k;
    while (left < right) {
      long long mid = left + (right - left) / 2;
      long long count = dfs(0, 0, coins, 1LL, mid);
      if (count < k) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }
    return left;
  }
  long long dfs(int index, int count, vector<int>& coins, long long curr_lcm,
                long long target) {
    if (curr_lcm > target) return 0;
    if (index == coins.size()) {
      if (count > 0) {
        if (count % 2 == 0) {
          return -(target / curr_lcm);
        }
        return target / curr_lcm;
      }
      return 0;
    }
    return dfs(index + 1, count, coins, curr_lcm, target) +
           dfs(index + 1, count + 1, coins, lcm(coins[index], curr_lcm), target);
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> coins = {3, 6, 9};
  int result = sol.findKthSmallest(coins, 3);
  int result_expected = 9;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  coins = {5, 2};
  result = sol.findKthSmallest(coins, 7);
  result_expected = 12;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}