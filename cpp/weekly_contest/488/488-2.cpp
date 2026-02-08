//
// Created by Milo on 2/8/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
  vector<long long> mergeAdjacent(vector<int>& nums) {
    stack<long long> merge_nums;
    long long top = 0;
    for (int num : nums) {
      if (merge_nums.empty()) {
        merge_nums.push(num);
        continue;
      }
      top = merge_nums.top();
      long long merge_number = num;
      while (top == merge_number) {
        merge_number += top;
        merge_nums.pop();
        if (merge_nums.empty()) break;
        top = merge_nums.top();
      }
      merge_nums.push(merge_number);
    }
    vector<long long> result(merge_nums.size());
    for (int i = merge_nums.size() - 1; i >= 0; i--) {
      result[i] = merge_nums.top();
      merge_nums.pop();
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> nums = {3, 1, 1, 2};
  vector<long long> result = sol.mergeAdjacent(nums);
  vector<long long> result_expected = {3, 4};
  cout << "result : ";
  for (long long n : result) {
    cout << n << " ";
  }
  cout << endl;
  cout << "result_expected : ";
  for (long long n : result_expected) {
    cout << n << " ";
  }
  cout << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums = {2, 2, 4};
  result = sol.mergeAdjacent(nums);
  result_expected = {8};
  cout << "result : ";
  for (long long n : result) {
    cout << n << " ";
  }
  cout << endl;
  cout << "result_expected : ";
  for (long long n : result_expected) {
    cout << n << " ";
  }
  cout << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  nums = {3, 7, 5};
  result = sol.mergeAdjacent(nums);
  result_expected = {3, 7, 5};
  cout << "result : ";
  for (long long n : result) {
    cout << n << " ";
  }
  cout << endl;
  cout << "result_expected : ";
  for (long long n : result_expected) {
    cout << n << " ";
  }
  cout << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}