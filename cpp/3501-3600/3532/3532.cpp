//
// Created by Milo on 7/9/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                    vector<vector<int>>& queries) {
    int group_id = 0;
    vector<int> group(n);
    for (int i = 0; i < n - 1; i++) {
      if (nums[i + 1] - nums[i] <= maxDiff) {
        group[i + 1] = group_id;
      } else {
        group_id++;
        group[i + 1] = group_id;
      }
    }
    vector<bool> result;
    result.reserve(queries.size());
    for (const auto& q : queries) {
      if (group[q[0]] == group[q[1]]) {
        result.push_back(true);
      } else {
        result.push_back(false);
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
  vector<vector<int>> queries = {{0, 0}, {0, 1}};
  vector<bool> result = sol.pathExistenceQueries(2, nums, 1, queries);
  vector<bool> result_expected = {true, false};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums = {2, 5, 6, 8};
  queries = {{0, 1}, {0, 2}, {1, 3}, {2, 3}};
  result = sol.pathExistenceQueries(4, nums, 2, queries);
  result_expected = {false, false, true, true};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}