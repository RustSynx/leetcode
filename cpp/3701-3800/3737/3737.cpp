//
// Created by Milo on 6/25/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int countMajoritySubarrays(vector<int>& nums, int target) {
    int n = static_cast<int>(nums.size());
    int result = 0;
    for (int i = 0; i < n; i++) {
      int size = 1;
      int target_count = 0;
      for (int j = i; j < n; j++) {
        if (nums[j] == target) target_count++;
        if (target_count > size / 2) {
          result++;
        }
        size++;
      }
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector nums = {1,2,2,3};
  int result = sol.countMajoritySubarrays(nums, 2);
  int result_expected = 5;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums = {1,1,1,1};
  result = sol.countMajoritySubarrays(nums, 1);
  result_expected = 10;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  nums = {1,2,3};
  result = sol.countMajoritySubarrays(nums, 4);
  result_expected = 0;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}