//
// Created by Milo on 6/8/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> pivotArray(vector<int> &nums, int pivot) {
    int n = static_cast<int>(nums.size());
    vector<int> result(n, pivot);
    int left = 0;
    int right = n - 1;
    for (int i = 0, j = n - 1; i < n; i++, j--) {
      if (nums[i] < pivot) {
        result[left++] = nums[i];
      }
      if (nums[j] > pivot) {
        result[right--] = nums[j];
      }
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> nums = {9, 12, 5, 10, 14, 3, 10};
  vector<int> result = sol.pivotArray(nums, 10);
  vector<int> result_expected = {9, 5, 3, 10, 10, 12, 14};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums = {-3, 4, 3, 2};
  result = sol.pivotArray(nums, 2);
  result_expected = {-3, 2, 4, 3};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}