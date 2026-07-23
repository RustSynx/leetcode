//
// Created by Milo on 7/23/26.
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
      int result = n;
      if (n > 2) {
        int bit_len = 0;
        while (n > 0) {
          bit_len++;
          n >>= 1;
        }
        result = 1;
        result <<= bit_len;
      }
      return result;
    }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> nums = {1, 2};
  int result = sol.uniqueXorTriplets(nums);
  int result_expected = 2;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums = {3, 1, 2};
  result = sol.uniqueXorTriplets(nums);
  result_expected = 4;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}