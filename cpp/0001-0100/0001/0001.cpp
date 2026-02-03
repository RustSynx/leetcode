//
// Created by Milo on 2/2/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    return twoSumNaive(nums, target);
  }
  vector<int> twoSumNaive(vector<int>& nums, int target) {
    vector<int> result;
    for (int i = 0; i < nums.size(); i++) {
      for (int j = i + 1; j < nums.size(); j++) {
        if (target == nums[i] + nums[j]) {
          result.push_back(i);
          result.push_back(j);
          return result;
        }
      }
    }
    return result;
  }
  vector<int> twoSumOptimized(vector<int>& nums, int target) {
    vector<int> result;
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++) {
      int pairNumber = target - nums[i];
      if (map.find(pairNumber) != map.end()) {
        result.push_back(i);
        result.push_back(map[pairNumber]);
      }
      map[nums[i]] = i;
    }
    sort(result.begin(), result.end());
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  vector<int> nums1 = {2, 7, 11, 15};
  int target1 = 9;
  vector<int> result1 = sol.twoSum(nums1, target1);

  cout << "Test Case 1: ";
  assert(result1[0] == 0 && result1[1] == 1);
  cout << "PASSED" << endl;

  // Test Case 2
  vector<int> nums2 = {3, 2, 4};
  int target2 = 6;
  vector<int> result2 = sol.twoSum(nums2, target2);

  cout << "Test Case 2: ";
  assert(result2[0] == 1 && result2[1] == 2);
  cout << "PASSED" << endl;

  // Test Case 3
  vector<int> nums3 = {3, 3};
  int target3 = 6;
  vector<int> result3 = sol.twoSum(nums3, target3);

  cout << "Test Case 3: ";
  assert(result3[0] == 0 && result3[1] == 1);
  cout << "PASSED" << endl;

  return 0;
}