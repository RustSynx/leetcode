//
// Created by Milo on 5/22/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int search(vector<int>& nums, int target) {
    int start = 0;
    int end = nums.size();
    while (start < end) {
      int mid = start + (end - start) / 2;
      if (nums[mid] == target) return mid;
      if (nums[start] < nums[mid]) {
        if (nums[start] <= target && target < nums[mid]) {
          end = mid;
        } else {
          start = mid + 1;
        }
      } else {
        if (nums[mid] <= target && target <= nums[end - 1]) {
          start = mid + 1;
        } else {
          end = mid;
        }
      }
    }
    return -1;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> nums = {4,5,6,7,0,1,2};
  int target = 0;
  int result = sol.search(nums, target);
  int result_expected = 4;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums = {4,5,6,7,0,1,2};
  target = 3;
  result = sol.search(nums, target);
  result_expected = -1;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  nums = {1};
  target = 0;
  result = sol.search(nums, target);
  result_expected = -1;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 4
  cout << "Test Case 4: " << endl;
  nums = {6, 7, 1, 2, 3, 4, 5};
  target = 7;
  result = sol.search(nums, target);
  result_expected = 1;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}