//
// Created by Milo on 5/21/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
  int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
    unordered_set<int> prefix_set;
    for (int num: arr1) {
      while (num > 0) {
        prefix_set.insert(num);
        num /= 10;
      }
    }
    int result = 0;
    for (int num : arr2) {
      while (num > 0) {
        if (prefix_set.contains(num)) {
          int len = to_string(num).length();
          result = max(result, len);
          break;
        }
        num /= 10;
      }
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> arr1 = {1,10,100};
  vector<int> arr2 = {1000};
  int result = sol.longestCommonPrefix(arr1, arr2);
  int result_expected = 3;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  arr1 = {1, 2, 3};
  arr2 = {4, 4, 4};
  result = sol.longestCommonPrefix(arr1, arr2);
  result_expected = 0;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}