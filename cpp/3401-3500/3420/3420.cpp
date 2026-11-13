//
// Created by Milo on 11/13/26.
//
#include <algorithm>
#include <cassert>
#include <deque>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
    int n = nums.size();
    deque<pair<long long, int>> dq;
    int right = n - 1;
    long long current_operations = 0;
    long long result = 0;
    for (int left = n - 1; left >= 0; left--) {
      int count = 1;
      while (!dq.empty() && dq.front().first < nums[left]) {
        auto [val, cnt] = dq.front();
        dq.pop_front();
        current_operations += (long long)(nums[left] - val) * cnt;
        count += cnt;
      }
      dq.push_front({nums[left], count});
      while (current_operations > k) {
        long long target_val = dq.back().first;
        current_operations -= (target_val - nums[right]);
        dq.back().second--;
        if (dq.back().second == 0) {
          dq.pop_back();
        }
        right--;
      }
      result += (right - left + 1);
    }
    return result;
  }
};

int main() {
  Solution sol;
  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> nums = {6, 3, 1, 2, 4, 4};
  int result = sol.countNonDecreasingSubarrays(nums, 7);
  int result_expected = 17;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums = {6, 3, 1, 3, 6};
  result = sol.countNonDecreasingSubarrays(nums, 4);
  result_expected = 12;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}