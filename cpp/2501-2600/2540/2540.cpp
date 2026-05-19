//
// Created by Milo on 5/19/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int getCommon(vector<int>& nums1, vector<int>& nums2) {
    int n1 = static_cast<int>(nums1.size());
    int n2 = static_cast<int>(nums2.size());
    int nums1_idx = 0;
    int nums2_idx = 0;
    while (nums1_idx < n1 && nums2_idx < n2) {
      if (nums1[nums1_idx] == nums2[nums2_idx]) return nums1[nums1_idx];
      if (nums1[nums1_idx] > nums2[nums2_idx]) {
        nums2_idx++;
      } else {
        nums1_idx++;
      }
    }
    return -1;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> nums1 = {1, 2, 3};
  vector<int> nums2 = {2, 4};
  int result = sol.getCommon(nums1, nums2);
  int result_expected = 2;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums1 = {1, 2, 3, 6};
  nums2 = {2, 3, 4, 5};
  result = sol.getCommon(nums1, nums2);
  result_expected = 2;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}