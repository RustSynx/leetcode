//
// Created by Milo on 7/16/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
 public:
  long long gcdSum(vector<int>& nums) {
    int n = nums.size();
    vector<int> prefix_gcd(n);
    int num_max = 0;
    for (int i = 0; i < n; i++) {
      num_max = max(num_max, nums[i]);
      prefix_gcd[i] = gcd(nums[i], num_max);
    }
    ranges::sort(prefix_gcd);
    long long result = 0;
    for (int i = 0; i < n / 2; i++) {
      result += gcd(prefix_gcd[i], prefix_gcd[n - i - 1]);
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> nums = {2, 6, 4};
  long long result = sol.gcdSum(nums);
  long long result_expected = 2;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums = {3, 6, 2, 8};
  result = sol.gcdSum(nums);
  result_expected = 5;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}