//
// Created by Milo on 2/15/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> toggleLightBulbs(vector<int>& bulbs) {
    vector<int> result;
    unordered_map<int, int> check_switch;
    for (int i = 0; i < bulbs.size(); i++) {
      if (check_switch.count(bulbs[i]) && check_switch[bulbs[i]] == 1) {
        check_switch[bulbs[i]] = 0;
      } else {
        check_switch[bulbs[i]] = 1;
      }
    }
    for (auto [num, val] : check_switch) {
      if (val) {
        result.push_back(num);
      }
    }
    sort(result.begin(), result.end());
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> nums = {10, 30, 20, 10};
  vector<int> result = sol.toggleLightBulbs(nums);
  for (int num:result) {
    cout << num << endl;
  }
  vector<int> result_expected = {20, 30};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums = {100, 100};
  result = sol.toggleLightBulbs(nums);
  result_expected = {};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}