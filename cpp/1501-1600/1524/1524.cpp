//
// Created by Milo on 11/15/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int numOfSubarrays(vector<int>& arr) {
    int mod = 1'000'000'007;
    int even_cnt = 1;
    int odd_cnt = 0;
    int curr_sum = 0;
    int result = 0;
    for (int n : arr) {
      curr_sum += n;
      if (curr_sum % 2 == 0) {
        result = (result + odd_cnt) % mod;
        even_cnt++;
      } else {
        result = (result + even_cnt) % mod;
        odd_cnt++;
      }
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> arr = {1, 3, 5};
  int result = sol.numOfSubarrays(arr);
  int result_expected = 4;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  arr = {2, 4, 6};
  result = sol.numOfSubarrays(arr);
  result_expected = 0;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  arr = {1, 2, 3, 4, 5, 6, 7};
  result = sol.numOfSubarrays(arr);
  result_expected = 16;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}