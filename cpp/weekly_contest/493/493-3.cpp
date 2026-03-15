//
// Created by Milo on 3/15/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

class Solution {
 public:
  int longestArithmetic(vector<int>& nums) {
    int result = 0;
    vector<pair<int, int>> diff_groups;
    diff_groups.reserve(nums.size());
    int prev_diff = nums[0] - nums[1];
    int diff_count = 0;
    for (int i = 0; i < nums.size() - 1; i++) {
      int diff = nums[i] - nums[i + 1];
      if (prev_diff == diff) {
        diff_count++;
      } else {
        diff_groups.emplace_back(prev_diff, diff_count);
        prev_diff = diff;
        diff_count = 1;
      }
    }
    diff_groups.emplace_back(prev_diff, diff_count);
    int sum = 0;
    for (int i = 0; i < diff_groups.size(); i++) {
      sum += diff_groups[i].second;
      if (i + 2 < diff_groups.size() && diff_groups[i + 1].second == 1 &&
          diff_groups[i + 2].second == 1 &&
          diff_groups[i + 1].first + diff_groups[i + 2].first ==
              diff_groups[i].first * 2) {
        sum += 2;
        if (i + 3 < diff_groups.size() &&
            diff_groups[i + 3].first == diff_groups[i].first) {
          sum += diff_groups[i + 3].second;
        }
      } else if (i + 2 < diff_groups.size() && diff_groups[i].second == 1 &&
                 diff_groups[i + 1].second == 1 &&
                 diff_groups[i].first + diff_groups[i + 1].first ==
                     diff_groups[i + 2].first * 2) {
        sum += diff_groups[i + 2].second + 1;
        if (i + 3 < diff_groups.size() &&
            diff_groups[i + 3].first == diff_groups[i + 2].first) {
          sum += diff_groups[i + 3].second;
        }
      } else {
        sum += 1;
      }
      result = max(result, sum);
      sum = 0;
    }
    return min(result + 1, static_cast<int>(nums.size()));
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> input = {9, 7, 5, 10, 1};
  int result = sol.longestArithmetic(input);
  int result_expected = 5;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  input = {1, 2, 6, 7};
  result = sol.longestArithmetic(input);
  result_expected = 3;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}