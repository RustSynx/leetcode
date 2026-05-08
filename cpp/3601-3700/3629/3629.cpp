//
// Created by Milo on 5/8/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
 public:
  int minJumps(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return 0;

    int max_val = 0;
    for (int num : nums) max_val = max(max_val, num);
    vector<bool> is_prime(max_val + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= max_val; ++i) {
      if (is_prime[i]) {
        for (int j = i * i; j <= max_val; j += i) {
          is_prime[j] = false;
        }
      }
    }

    unordered_map<int, vector<int>> idx_map;
    for (int i = 0; i < n; ++i) {
      idx_map[nums[i]].push_back(i);
    }

    queue<pair<int, int>> q;
    q.push({0, 0});

    vector<bool> visited_idx(n, false);
    vector<bool> visited_prime(max_val + 1, false);
    visited_idx[0] = true;

    while (!q.empty()) {
      auto [idx, jump_cnt] = q.front();
      q.pop();

      if (idx == n - 1) return jump_cnt;

      int val = nums[idx];

      if (is_prime[val] && !visited_prime[val]) {
        visited_prime[val] = true;

        for (int mult = val; mult <= max_val; mult += val) {
          if (idx_map.contains(mult)) {
            for (int jump_idx : idx_map[mult]) {
              if (!visited_idx[jump_idx]) {
                visited_idx[jump_idx] = true;
                q.push({jump_idx, jump_cnt + 1});
              }
            }
          }
        }
      }

      if (idx + 1 < n && !visited_idx[idx + 1]) {
        visited_idx[idx + 1] = true;
        q.push({idx + 1, jump_cnt + 1});
      }

      if (idx - 1 >= 0 && !visited_idx[idx - 1]) {
        visited_idx[idx - 1] = true;
        q.push({idx - 1, jump_cnt + 1});
      }
    }

    return 0;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> nums = {1, 2, 4, 6};
  int result = sol.minJumps(nums);
  int result_expected = 2;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums = {2, 3, 4, 7, 9};
  result = sol.minJumps(nums);
  result_expected = 2;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  nums = {4, 6, 5, 8};
  result = sol.minJumps(nums);
  result_expected = 3;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}