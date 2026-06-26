//
// Created by Milo on 6/26/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  long long countMajoritySubarrays(vector<int>& nums, int target) {
    int n = static_cast<int>(nums.size());

    int offset = n + 1;
    vector bit(2 * offset, 0);

    auto add = [&](int idx, int val) {
      for (; idx < bit.size(); idx += idx & -idx) {
        bit[idx] += val;
      }
    };

    auto query = [&](int idx) {
      int sum = 0;
      for (; idx > 0; idx -= idx & -idx) {
        sum += bit[idx];
      }
      return sum;
    };

    int prefix_sum = 0;
    long long result = 0;

    add(offset, 1);
    for (int i = 0; i < n; i++) {
      if (nums[i] == target) {
        prefix_sum += 1;
      } else {
        prefix_sum -= 1;
      }
      result += query(prefix_sum - 1 + offset);
      add(prefix_sum + offset, 1);
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector nums = {1,2,2,3};
  int result = sol.countMajoritySubarrays(nums, 2);
  int result_expected = 5;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums = {1,1,1,1};
  result = sol.countMajoritySubarrays(nums, 1);
  result_expected = 10;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  nums = {1,2,3};
  result = sol.countMajoritySubarrays(nums, 4);
  result_expected = 0;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}