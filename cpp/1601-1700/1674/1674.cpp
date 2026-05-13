//
// Created by Milo on 5/13/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int minMoves(vector<int>& nums, int limit) {
    int n = static_cast<int>(nums.size());
    int max_len = limit * 2;
    vector<int> prefix_sum(max_len + 2, 0);
    for (int i = 0; i < n / 2; i++) {
      int a = min(nums[i], nums[n - 1 - i]);
      int b = max(nums[i], nums[n - 1 - i]);

      prefix_sum[2] += 2;
      prefix_sum[1 + a] -= 1;
      prefix_sum[a + b] -= 1;
      prefix_sum[a + b + 1] += 1;
      prefix_sum[b + limit + 1] += 1;
    }

    int result = INT_MAX;
    int curr_sum = 0;
    for (int i = 2; i <= max_len; i++) {
      curr_sum += prefix_sum[i];
      result = min(result, curr_sum);
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> nums = {1, 2, 4, 3};
  int result = sol.minMoves(nums, 4);
  int result_expected = 1;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums = {1, 2, 2, 1};
  result = sol.minMoves(nums, 2);
  result_expected = 2;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  nums = {1, 2, 1, 2};
  result = sol.minMoves(nums, 2);
  result_expected = 0;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}