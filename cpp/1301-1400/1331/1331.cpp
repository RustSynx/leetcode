//
// Created by Milo on 7/12/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> arrayRankTransform(vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return arr;
    vector<pair<int, int>> ordered_arr(n);
    for (int i = 0; i < n; i++) {
      ordered_arr[i] = make_pair(i, arr[i]);
    }
    int rank = 1;
    ranges::sort(ordered_arr, [](const auto& a, const auto& b) {
      return a.second < b.second;
    });
    arr[ordered_arr[0].first] = rank;
    for (int i = 1; i < n; i++) {
      if (ordered_arr[i - 1].second < ordered_arr[i].second) {
        rank++;
      }
      arr[ordered_arr[i].first] = rank;
    }
    return arr;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> arr = {40, 10, 20, 30};
  vector<int> result = sol.arrayRankTransform(arr);
  vector<int> result_expected = {4, 1, 2, 3};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  arr = {100, 100, 100};
  result = sol.arrayRankTransform(arr);
  result_expected = {1, 1, 1};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  arr = {37, 12, 28, 9, 100, 56, 80, 5, 12};
  result = sol.arrayRankTransform(arr);
  result_expected = {5, 3, 4, 2, 8, 6, 7, 1, 3};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}