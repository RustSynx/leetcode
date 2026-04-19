//
// Created by Milo on 4/19/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxDistance(vector<int>& nums1, vector<int>& nums2) {
    int result = 0;
    int i = 0, j = 0;
    while (i < nums1.size() && j < nums2.size()) {
      if (nums1[i] <= nums2[j]) {
        result = max(result, j - i);
      } else if (nums1[i] > nums2[j]) {
        i++;
      }
      j++;
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> nums1 = {55, 30, 5, 4, 2};
  vector<int> nums2 = {100, 20, 10, 10, 5};
  int result = sol.maxDistance(nums1, nums2);
  int result_expected = 2;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums1 = {2, 2, 2};
  nums2 = {10, 10, 1};
  result = sol.maxDistance(nums1, nums2);
  result_expected = 1;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  nums1 = {30, 29, 19, 5};
  nums2 = {25, 25, 25, 25, 25};
  result = sol.maxDistance(nums1, nums2);
  result_expected = 2;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}