//
// Created by Milo on 8/25/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int missingMultiple(vector<int>& nums, int k) {
    bool check_num[101] = {};
    for (int num : nums) {
      check_num[num] = true;
    }
    for (int i = k; i < 201; i += k) {
      if (i > 100) return i;
      if (!check_num[i]) return i;
    }
    return k;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector nums = {8, 2, 3, 4, 6};
  int result = sol.missingMultiple(nums, 2);
  int result_expected = 10;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums = {1, 4, 7, 10, 15};
  result = sol.missingMultiple(nums, 5);
  result_expected = 5;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}