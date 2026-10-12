//
// Created by Milo on 10/12/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int maxSum(vector<int>& nums, int k) {
    int mod = 1e9 + 7;
    vector<int> bit_count(30);
    for (int n : nums) {
      int idx = 0;
      while (n > 0) {
        if ((n & 1) == 1) {
          bit_count[idx]++;
        }
        n >>= 1;
        idx++;
      }
    }
    int result = 0;
    for (int i = 0; i < k; i++) {
      int sum = 0;
      for (int j = 0; j < 30; j++) {
        if (bit_count[j] > 0) {
          bit_count[j]--;
          sum += 1 << j;
        }
      }
      result = (result + static_cast<long long>(sum) * sum % mod) % mod;
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> nums = {2,6,5,8};
  int result = sol.maxSum(nums, 2);
  int result_expected = 261;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums = {4,5,4,7};
  result = sol.maxSum(nums, 3);
  result_expected = 90;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}