//
// Created by Milo on 5/10/26.
//
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  long long minArraySum(vector<int>& nums) {
    int max_val = *max_element(nums.begin(), nums.end());
    vector<bool> exist(max_val + 1, false);
    for (int num : nums) {
      exist[num] = true;
    }
    vector<int> min_vec(max_val + 1, 0);
    for (int i = 1; i <= max_val; i++) {
      if (!exist[i]) continue;
      for (int j = i; j <= max_val; j += i) {
        if (min_vec[j] == 0) {
          min_vec[j] = i;
        }
      }
    }
    long long sum = 0;
    for (int num : nums) {
      sum += min_vec[num];
    }
    return sum;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> nums = {3, 6, 2};
  long long result = sol.minArraySum(nums);
  long long result_expected = 7;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums = {4,2,8,3};
  result = sol.minArraySum(nums);
  result_expected = 9;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  nums = {7, 5, 9};
  result = sol.minArraySum(nums);
  result_expected = 21;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}