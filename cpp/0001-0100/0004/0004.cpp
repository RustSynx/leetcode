//
// Created by Milo on 2/5/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

class Solution {
 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() > nums2.size()) {
      return findMedianSortedArrays(nums2, nums1);
    }
    size_t nums1_index = nums1.empty()       ? 0
                         : nums1.size() == 1 ? 1
                                             : nums1.size() / 2,
           nums2_index = (nums1.size() + nums2.size() + 1) / 2 - nums1_index;
    nums2_index = nums2_index > nums2.size() ? nums2.size() : nums2_index;
    while (true) {
      int nums1_right_value =
          nums1_index < nums1.size() ? nums1[nums1_index] : INT_MAX;
      int nums1_left_value = nums1_index > 0 ? nums1[nums1_index - 1] : INT_MIN;
      int nums2_right_value =
          nums2_index < nums2.size() ? nums2[nums2_index] : INT_MAX;
      int nums2_left_value = nums2_index > 0 ? nums2[nums2_index - 1] : INT_MIN;
      if (nums1_left_value <= nums2_right_value &&
          nums2_left_value <= nums1_right_value) {
        if (nums1.empty()) {
          nums1_right_value = 0;
          nums1_left_value = 0;
        }
        if (nums2.empty()) {
          nums2_right_value = 0;
          nums2_left_value = 0;
        }
        if ((nums1.size() + nums2.size()) % 2 == 0) {
          return (max(nums1_left_value, nums2_left_value) +
                  min(nums1_right_value, nums2_right_value)) /
                 2.0;
        }
        return max(nums1_left_value, nums2_left_value);
      }
      if (nums1_left_value > nums2_right_value) {
        nums1_index -= 1;
      } else {
        nums1_index += 1;
      }
      nums2_index = (nums1.size() + nums2.size() + 1) / 2 - nums1_index;
    }
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1" << endl;
  vector<int> nums1 = {1, 3};
  vector<int> nums2 = {2};
  double result = sol.findMedianSortedArrays(nums1, nums2);
  double result_expected = 2.0;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2" << endl;
  nums1 = {1, 2};
  nums2 = {3, 4};
  result = sol.findMedianSortedArrays(nums1, nums2);
  result_expected = 2.5;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}