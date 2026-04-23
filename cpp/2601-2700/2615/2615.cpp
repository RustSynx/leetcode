//
// Created by Milo on 4/23/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  vector<long long> distance(vector<int>& nums) {
    int n = static_cast<int>(nums.size());
    unordered_map<int, vector<int>> index_map;
    for (int i = 0; i < n; i++) {
      index_map[nums[i]].push_back(i);
    }
    vector<long long> result(n);
    for (auto& map : index_map) {
      int idx_size = static_cast<int>(map.second.size());
      if (idx_size == 1) continue;
      long long prefix_sum = 0;
      for (int n : map.second) {
        prefix_sum += n;
      }
      long long left_sum = 0;
      long long right_sum = prefix_sum;
      for (int i = 0; i < idx_size; i++) {
        long long right_cnt = idx_size - i - 1;
        long long current_idx = map.second[i];
        right_sum -= map.second[i];
        result[map.second[i]] = current_idx * i - left_sum + right_sum - current_idx * right_cnt;
        left_sum += map.second[i];
      }
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> nums = {1, 3, 1, 1, 2};
  vector<long long> result = sol.distance(nums);
  vector<long long> result_expected = {5, 0, 3, 4, 0};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums = {0, 5, 3};
  result = sol.distance(nums);
  result_expected = {0, 0, 0};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}