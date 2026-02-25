//
// Created by Milo on 2/25/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

class Solution {
 public:
  vector<int> sortByBits(vector<int>& arr) {
    vector<int> result = arr;
    sort(result.begin(), result.end(), [](int a, int b) {
      int a_one_bit_count = __builtin_popcount(a);
      int b_one_bit_count = __builtin_popcount(b);

      if (a_one_bit_count != b_one_bit_count) {
        return a_one_bit_count < b_one_bit_count;
      }

      return a < b;
    });
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> input = {0, 1, 2, 3, 4, 5, 6, 7, 8};
  vector<int> result = sol.sortByBits(input);
  vector<int> result_expected = {0, 1, 2, 4, 8, 3, 5, 6, 7};
  cout << "result : ";
  for (int num : result) {
    cout << num << " ";
  }
  cout << endl;
  cout << "result_expected : ";
  for (int num : result_expected) {
    cout << num << " ";
  }
  cout << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  input = {1024, 512, 256, 128, 64, 32, 16, 8, 4, 2, 1};
  result = sol.sortByBits(input);
  result_expected = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};
  cout << "result : ";
  for (int num : result) {
    cout << num << " ";
  }
  cout << endl;
  cout << "result_expected : ";
  for (int num : result_expected) {
    cout << num << " ";
  }
  cout << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}