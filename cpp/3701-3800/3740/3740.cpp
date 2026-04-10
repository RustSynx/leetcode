//
// Created by Milo on 4/10/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int minimumDistance(vector<int>& nums) {
    int n = static_cast<int>(nums.size());
    if (n < 3) return -1;
    int result = INT_MAX;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        for (int k = j + 1; k < n; k++) {
          if (nums[i] == nums[j] && nums[j] == nums[k]) {
            result = min(result, abs(i-j) + abs(j-k) + abs(k-i));
          }
        }
      }
    }
    return result == INT_MAX ? -1 : result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector nums = {1, 2, 1, 1, 3};
  int result = sol.minimumDistance(nums);
  int result_expected = 6;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums = {1, 1, 2, 3, 2, 1, 2};
  result = sol.minimumDistance(nums);
  result_expected = 8;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  nums = {1};
  result = sol.minimumDistance(nums);
  result_expected = -1;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}