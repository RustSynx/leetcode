//
// Created by Milo on 2/22/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int scoreDifference(vector<int>& nums) {
    bool check_active = true;
    int first_player_score = 0;
    int second_player_score = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] % 2 != 0) {
        check_active = !check_active;
      }
      if ((i + 1) % 6 == 0) {
        check_active = !check_active;
      }
      if (check_active) {
        first_player_score += nums[i];
      } else {
        second_player_score += nums[i];
      }
    }
    return first_player_score - second_player_score;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> nums = {1, 2, 3};
  int result = sol.scoreDifference(nums);
  int result_expected = 0;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums = {2, 4, 2, 1, 2, 1};
  result = sol.scoreDifference(nums);
  result_expected = 4;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums = {1};
  result = sol.scoreDifference(nums);
  result_expected = -1;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}