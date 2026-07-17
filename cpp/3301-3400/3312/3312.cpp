//
// Created by Milo on 7/17/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
    int max_val = *max_element(nums.begin(), nums.end());
    vector<int> freq(max_val + 1, 0);
    for (int num : nums) {
      freq[num]++;
    }
    vector<long long> gcd_count(max_val + 1);
    for (int i = max_val; i > 0; i--) {
      long long c = 0;
      for (int j = i; j <= max_val; j += i) {
        c += freq[j];
      }
      long long pairs = c * (c - 1) / 2;
      for (int j = i * 2; j <= max_val; j += i) {
        pairs -= gcd_count[j];
      }
      gcd_count[i] = pairs;
    }
    vector<long long> prefix_gcd(max_val + 1);
    for (int i = 1; i < max_val + 1; i++) {
      prefix_gcd[i] = prefix_gcd[i - 1] + gcd_count[i];
    }
    vector<int> result;
    result.reserve(queries.size());
    for (long long q : queries) {
      auto it = upper_bound(prefix_gcd.begin(), prefix_gcd.end(), q);
      result.push_back(it - prefix_gcd.begin());
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> nums = {2, 3, 4};
  vector<long long> queries = {0, 2, 2};
  vector<int> result = sol.gcdValues(nums, queries);
  vector<int> result_expected = {1, 2, 2};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums = {4, 4, 2, 1};
  queries = {5, 3, 1, 0};
  result = sol.gcdValues(nums, queries);
  result_expected = {4, 2, 1, 1};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  nums = {2, 2};
  queries = {0, 0};
  result = sol.gcdValues(nums, queries);
  result_expected = {2, 2};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}