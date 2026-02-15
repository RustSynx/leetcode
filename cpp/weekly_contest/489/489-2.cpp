//
// Created by Milo on 2/15/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <deque>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
 public:
  int firstUniqueFreq(vector<int>& nums) {
    int result = -1;
    unordered_map<int, int> check_freq;
    for (int num : nums) {
      if (check_freq.count(num)) {
        check_freq[num]++;
      } else {
        check_freq[num] = 1;
      }
    }
    unordered_map<int, int> check_unique;
    unordered_map<int, unordered_set<int>> duplications;
    for (auto [key, value] : check_freq) {
      duplications[value].insert(key);
    }
    deque<int> dq;
    int order_num = INT_MAX;
    for (auto [key, value] : duplications) {
      if (value.size() == 1) {
        int val = *value.begin();
        int index = find(nums.begin(), nums.end(), val) - nums.begin();
        if (order_num > index) {
          order_num = index;
          dq.push_front(val);
        } else {
          dq.push_back(val);
        }
      }
    }
    if (!dq.empty()) return dq.front();
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> nums = {20, 10, 30, 30};
  int result = sol.firstUniqueFreq(nums);
  int result_expected = 30;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums = {20, 20, 10, 30, 30, 30};
  result = sol.firstUniqueFreq(nums);
  result_expected = 20;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums = {1,1,2};
  result = sol.firstUniqueFreq(nums);
  result_expected = 1;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}