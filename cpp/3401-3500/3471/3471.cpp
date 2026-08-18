//
// Created by Milo on 8/18/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  int largestInteger(vector<int>& nums, int k) {
    int n = nums.size();
    unordered_map<int, int> map;
    for (int i = 0; i <= n - k; i++) {
      unordered_set<int> subarray(nums.begin() + i, nums.begin() + i + k);
      for (int num : subarray) {
        map[num]++;
      }
    }
    int result = -1;
    for (auto [num, count] : map) {
      if (count == 1) {
        result = max(result, num);
      }
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> nums = {3, 9, 2, 1, 7};
  int result = sol.largestInteger(nums, 3);
  int result_expected = 7;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums = {3, 9, 7, 2, 1, 7};
  result = sol.largestInteger(nums, 4);
  result_expected = 3;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  nums = {0, 0};
  result = sol.largestInteger(nums, 1);
  result_expected = -1;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}