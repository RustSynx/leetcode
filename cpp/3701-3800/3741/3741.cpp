//
// Created by Milo on 4/11/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int minimumDistance(vector<int>& nums) {
    int n = static_cast<int>(nums.size());
    unordered_map<int, vector<int>> val_idx;
    for (int i = 0; i < n; i++) {
      val_idx[nums[i]].push_back(i);
    }
    int result = INT_MAX;
    for (const auto& [val, idx] : val_idx) {
      int len = static_cast<int>(idx.size());
      if (len < 3) {
        continue;
      }
      for (int i = 0; i < len - 2; i++) {
        result = min(result, 2 * (idx[i + 2] - idx[i]));
      }
    }
    return result == INT_MAX ? -1 : result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> nums = {1, 2, 1, 1, 3};
  int result = sol.minimumDistance(nums);
  int result_expected = 6;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums = {1, 1, 2, 3, 2, 1, 2};
  result = sol.minimumDistance(nums);
  result_expected = 8;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  nums = {1};
  result = sol.minimumDistance(nums);
  result_expected = -1;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}