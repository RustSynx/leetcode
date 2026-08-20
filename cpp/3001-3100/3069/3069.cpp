//
// Created by Milo on 8/20/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> resultArray(vector<int>& nums) {
    int n = nums.size();
    vector<int> arr1;
    vector<int> arr2;
    arr1.push_back(nums[0]);
    arr2.push_back(nums[1]);
    for (int i = 2; i < n; i++) {
      if (arr1.back() > arr2.back()) {
        arr1.push_back(nums[i]);
      } else {
        arr2.push_back(nums[i]);
      }
    }
    arr1.insert(arr1.end(), arr2.begin(), arr2.end());
    return arr1;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> nums = {2, 1, 3};
  vector<int> result = sol.resultArray(nums);
  vector<int> result_expected = {2, 3, 1};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums = {5, 4, 3, 8};
  result = sol.resultArray(nums);
  result_expected = {5, 3, 4, 8};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}