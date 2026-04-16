//
// Created by Milo on 4/16/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
    int n = static_cast<int>(nums.size());
    unordered_map<int, vector<int>> nums_map;
    for (int i = 0; i < n; i++) {
      nums_map[nums[i]].push_back(i);
    }
    vector<int> result;
    result.reserve(queries.size());
    for (const int q : queries) {
      int distance = INT_MAX;
      if (nums_map.contains(nums[q]) && nums_map[nums[q]].size() > 1) {
        const vector<int>& q_idx_v = nums_map[nums[q]];
        auto current_it = lower_bound(q_idx_v.begin(), q_idx_v.end(), q);
        if (*current_it == q_idx_v.back()) {
          distance = min(distance, q_idx_v[0] + n - *current_it);
        } else {
          distance = min(distance, *next(current_it, 1) - *current_it);
        }
        if (current_it == q_idx_v.begin()) {
          distance = min(distance, n - q_idx_v.back() + *current_it);
        } else {
          distance = min(distance, *current_it - *prev(current_it, 1));
        }
        result.push_back(distance);
      } else {
        result.push_back(-1);
      }
    }
    return result;
  }
};

int main() {
  Solution sol;
  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> nums = {1, 3, 1, 4, 1, 3, 2};
  vector<int> queries = {0, 3, 5};
  vector<int> result = sol.solveQueries(nums, queries);
  vector<int> result_expected = {2, -1, 3};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums = {1, 2, 3, 4};
  queries = {0, 1, 2, 3};
  result = sol.solveQueries(nums, queries);
  result_expected = {-1, -1, -1, -1};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}