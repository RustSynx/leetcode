//
// Created by Milo on 4/17/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  int minMirrorPairDistance(vector<int>& nums) {
    int n = static_cast<int>(nums.size());
    unordered_map<int, int> reverse_map;
    int result = INT_MAX;
    for (int j = 0; j < n; j++) {
      int reverse_num = reverseInteger(nums[j]);
      if (reverse_map.contains(nums[j])) {
        result = min(result, j - reverse_map[nums[j]]);
      }
      reverse_map[reverse_num] = j;
    }
    return result == INT_MAX ? -1 : result;
  }
  int reverseInteger(int num) {
    long long reversed_num = 0;
    while (num > 0) {
      reversed_num = reversed_num * 10 + (num % 10);
      num /= 10;
    }
    return static_cast<int>(reversed_num);
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector nums = {12, 21, 45, 33, 54};
  int result = sol.minMirrorPairDistance(nums);
  int result_expected = 1;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums = {120, 21};
  result = sol.minMirrorPairDistance(nums);
  result_expected = 1;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  nums = {21, 120};
  result = sol.minMirrorPairDistance(nums);
  result_expected = -1;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}