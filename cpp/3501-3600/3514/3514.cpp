//
// Created by Milo on 7/24/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int uniqueXorTriplets(vector<int>& nums) {
    int n = nums.size();
    bool second_xor[2048] = {false};
    for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j++) {
        second_xor[nums[i] ^ nums[j]] = true;
      }
    }
    bool triple_xor[2048] = {false};
    int result = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 2048; j++) {
        if (!second_xor[j]) continue;
        int triple_v = nums[i] ^ j;
        if (!triple_xor[triple_v]) result++;
        triple_xor[triple_v] = true;
      }
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> nums = {1, 3};
  int result = sol.uniqueXorTriplets(nums);
  int result_expected = 2;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums = {6, 7, 8, 9};
  result = sol.uniqueXorTriplets(nums);
  result_expected = 4;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}