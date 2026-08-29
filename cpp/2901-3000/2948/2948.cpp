//
// Created by Milo on 8/29/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <ranges>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
    int n = nums.size();
    vector<pair<int,int>> pair_num(n);
    for (int i = 0; i < n; i++) {
      pair_num[i] = {nums[i], i};
    }
    ranges::sort(pair_num);
    vector<int> result = nums;
    int idx = 0;
    while (idx < n) {
      int j = idx + 1;

      while (j < n && pair_num[j].first - pair_num[j - 1].first <= limit) {
        j++;
      }
      vector<int> indices;
      indices.reserve(j - idx);
      for (int i = idx; i < j; i++) {
        indices.push_back(pair_num[i].second);
      }
      ranges::sort(indices);
      for (int i = 0; i < j - idx; i++) {
        result[indices[i]] = pair_num[i + idx].first;
      }
      idx = j;
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> nums = {1, 5, 3, 9, 8};
  vector<int> result = sol.lexicographicallySmallestArray(nums, 2);
  vector<int> result_expected = {1, 3, 5, 8, 9};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums = {1, 7, 6, 18, 2, 1};
  result = sol.lexicographicallySmallestArray(nums, 3);
  result_expected = {1, 6, 7, 18, 1, 2};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums = {1, 7, 28, 19, 10};
  result = sol.lexicographicallySmallestArray(nums, 3);
  result_expected = {1, 7, 28, 19, 10};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}