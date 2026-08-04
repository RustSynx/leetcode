//
// Created by Milo on 8/4/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> findMissingElements(vector<int>& nums) {
    int n = nums.size();
    ranges::sort(nums);
    int start = nums[0];
    int end = nums[n - 1];
    int idx = 0;
    vector<int> result;
    for (int i = start; i < end; i++) {
      if (nums[idx] == i) idx++;
      else result.push_back(i);
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector nums = {1, 4, 2, 5};
  vector<int> result = sol.findMissingElements(nums);
  vector<int> result_expected = {3};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums = {7, 8, 6, 9};
  result = sol.findMissingElements(nums);
  result_expected = {};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  nums = {5, 1};
  result = sol.findMissingElements(nums);
  result_expected = {2, 3, 4};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}