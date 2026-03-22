//
// Created by Milo on 3/22/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool uniformArray(vector<int>& nums1) {
    sort(nums1.begin(), nums1.end());
    int even_count = 0;
    for (int i = 0; i < nums1.size(); i++) {
      if (nums1[0] % 2 == 0 && i > 0 && nums1[i] % 2 != 0) return false;
      if (i == 0 && nums1[i] % 2 != 0) return true;
      even_count++;
    }
    return even_count == nums1.size() || even_count == 0;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> input = {1, 4, 7};
  bool result = sol.uniformArray(input);
  bool result_expected = true;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  input = {2, 3};
  result = sol.uniformArray(input);
  result_expected = false;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  input = {4, 6};
  result = sol.uniformArray(input);
  result_expected = true;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}