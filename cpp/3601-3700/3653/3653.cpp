//
// Created by Milo on 4/8/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
    int mod = 1e9 + 7;
    for (int i = 0; i < queries.size(); i++) {
      int size = queries[i][1];
      int step = queries[i][2];
      int vi = queries[i][3];
      for (int idx = queries[i][0]; idx <= size; idx+=step) {
        nums[idx] = static_cast<int>((1LL * nums[idx] * vi) % mod);
      }
    }
    int result = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      result = result ^ nums[i];
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> nums = {1, 1, 1};
  vector<vector<int>> queries = {{0, 2, 1, 4}};
  int result = sol.xorAfterQueries(nums, queries);
  int result_expected = 4;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums = {2, 3, 1, 5, 4};
  queries = {{1, 4, 2, 3}, {0, 2, 1, 2}};
  result = sol.xorAfterQueries(nums, queries);
  result_expected = 31;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}