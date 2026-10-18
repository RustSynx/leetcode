//
// Created by Milo on 10/18/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  int mod = 1e9 + 7;
  vector<vector<long long>> comb;

 public:
  int numOfWays(vector<int>& nums) {
    int n = nums.size();
    comb.assign(n + 1, vector<long long>(n + 1, 0));
    for (int i = 0; i <= n; ++i) {
      comb[i][0] = 1;
      for (int j = 1; j <= i; ++j) {
        comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % mod;
      }
    }
    return (dfs(nums) - 1 + mod) % mod;
  }
  long long dfs(vector<int>& nums) {
    int m = nums.size();
    if (m <= 2) return 1;
    vector<int> left, right;
    int root = nums[0];
    for (int i = 1; i < m; ++i) {
      if (nums[i] < root) {
        left.push_back(nums[i]);
      } else {
        right.push_back(nums[i]);
      }
    }
    long long left_c = dfs(left);
    long long right_c = dfs(right);
    long long l_r_c = comb[m - 1][left.size()];

    return left_c * right_c % mod * l_r_c % mod;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> nums = {2, 1, 3};
  int result = sol.numOfWays(nums);
  int result_expected = 1;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums = {3, 4, 5, 1, 2};
  result = sol.numOfWays(nums);
  result_expected = 5;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  nums = {1, 2, 3};
  result = sol.numOfWays(nums);
  result_expected = 0;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}