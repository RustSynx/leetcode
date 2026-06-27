//
// Created by Milo on 6/27/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maximumLength(vector<int>& nums) {
    int n = static_cast<int>(nums.size());
    unordered_map<long long, int> num_map;
    for (int i = 0; i < n; i++) {
      num_map[nums[i]]++;
    }
    int result = 1;
    if (num_map.contains(1) && num_map[1] > 1) {
      int one = 0;
      if (num_map[1] % 2 == 0) {
        one++;
      }
      result = max(result, num_map[1] - one);
    }

    for (int i = 0; i < n; i++) {
      if (nums[i] == 1) continue;
      int sum = 0;
      long long x = nums[i];
      while (num_map.contains(x) && num_map[x] > 1) {
        sum += 2;
        if (x * x > 1e9) break;
        x = x * x;
      }
      if (num_map.contains(x) && num_map[x] == 1) {
        sum++;
      } else {
        sum--;
      }
      result = max(result, sum);
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> nums = {5, 4, 1, 2, 2};
  int result = sol.maximumLength(nums);
  int result_expected = 3;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums = {1, 3, 2, 4};
  result = sol.maximumLength(nums);
  result_expected = 1;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}