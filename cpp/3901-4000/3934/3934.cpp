//
// Created by Milo on 11/25/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
 public:
  int smallestUniqueSubarray(vector<int>& nums) {
    int n = nums.size();
    long long B1 = 100003, M1 = 1'000'000'007;
    long long B2 = 1000019, M2 = 1'000'000'009;
    vector<long long> prefix_h1(n + 1);
    vector<long long> prefix_h2(n + 1);
    vector<long long> pow1(n + 1, 1);
    vector<long long> pow2(n + 1, 1);
    for (int i = 0; i < n; i++) {
      prefix_h1[i + 1] = (prefix_h1[i] * B1 + nums[i]) % M1;
      prefix_h2[i + 1] = (prefix_h2[i] * B2 + nums[i]) % M2;
      pow1[i + 1] = pow1[i] * B1 % M1;
      pow2[i + 1] = pow2[i] * B2 % M2;
    }
    auto check = [&](int len) -> bool {
      long long p1 = pow1[len];
      long long p2 = pow2[len];
      unordered_set<uint64_t> seen;
      seen.reserve(n - len + 1);
      unordered_set<uint64_t> duplicate;
      for (int i = 0; i < n - len + 1; i++) {
        long long h1 = (prefix_h1[i + len] - prefix_h1[i] * p1 % M1 + M1) % M1;
        long long h2 = (prefix_h2[i + len] - prefix_h2[i] * p2 % M2 + M2) % M2;
        uint64_t key = (static_cast<uint64_t>(h1) << 32) | static_cast<uint64_t>(h2);
        if (seen.contains(key)) {
          duplicate.insert(key);
        } else {
          seen.insert(key);
        }
      }
      return seen.size() > duplicate.size();
    };
    int left = 1, right = n;
    while (left < right) {
      int mid = left + (right - left) / 2;
      if (check(mid)) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }
    return left;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> nums = {3, 3, 3};
  int result = sol.smallestUniqueSubarray(nums);
  int result_expected = 3;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums = {2, 1, 2, 3, 3};
  result = sol.smallestUniqueSubarray(nums);
  result_expected = 1;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  nums = {1, 1, 2, 2, 1};
  result = sol.smallestUniqueSubarray(nums);
  result_expected = 2;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}