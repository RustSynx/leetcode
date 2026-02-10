//
// Created by Milo on 2/10/26.
//
#include <algorithm>
#include <cassert>
#include <deque>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution {
public:
  int longestBalanced(vector<int>& nums) {
    int result = 0;
    deque<int> sub_array;
    int odd_count = 0;
    int even_count = 0;
    unordered_set<int> check_distinct;
    for (int i = 0; i < nums.size(); i++) {
      check_distinct.clear();
      sub_array.clear();
      odd_count = 0;
      even_count = 0;
      for (int j = i; j < nums.size(); j++) {
        if (check_distinct.find(nums[j]) == check_distinct.end()) {
          if (nums[j] % 2 == 0) {
            even_count++;
          } else {
            odd_count++;
          }
        }
        check_distinct.insert(nums[j]);
        sub_array.push_back(nums[j]);
        if (sub_array.size() > result && even_count == odd_count) {
          result = sub_array.size();
        }
      }
    }
    if (sub_array.size() > result && even_count == odd_count) {
      result = sub_array.size();
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector nums = {2, 5, 4, 3};
  int result = sol.longestBalanced(nums);
  int result_expected = 4;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums = {3, 2, 2, 5, 4};
  result = sol.longestBalanced(nums);
  result_expected = 5;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  nums = {1, 2, 3, 2};
  result = sol.longestBalanced(nums);
  result_expected = 3;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}