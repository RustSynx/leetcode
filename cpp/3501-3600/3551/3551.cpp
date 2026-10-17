//
// Created by Milo on 10/17/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int minSwaps(vector<int>& nums) {
    int n = nums.size();
    vector<pair<int, int>> digits(n);
    for (int i = 0; i < n; i++) {
      int num = nums[i];
      int sum = 0;
      while (num > 0) {
        sum += num % 10;
        num /= 10;
      }
      digits[i] = {sum, i};
    }
    ranges::sort(digits, [&](pair<int, int>& a, pair<int, int>& b) {
      if (a.first == b.first) {
        return nums[a.second] < nums[b.second];
      }
      return a.first < b.first;
    });
    int result = 0;
    vector<bool> visited(n);
    for (int i = 0; i < n; i++) {
      int num = nums[i];
      if (visited[i] || i == digits[i].second) continue;
      int cycle = 0;
      int j = i;
      while (!visited[j]) {
        visited[j] = true;
        j = digits[j].second;
        cycle++;
      }
      if (cycle > 0) {
        result += cycle - 1;
      }
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> nums = {37, 100};
  int result = sol.minSwaps(nums);
  int result_expected = 1;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums = {22, 14, 33, 7};
  result = sol.minSwaps(nums);
  result_expected = 0;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  nums = {18, 43, 34, 16};
  result = sol.minSwaps(nums);
  result_expected = 2;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}