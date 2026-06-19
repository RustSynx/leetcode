//
// Created by Milo on 6/19/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int largestAltitude(vector<int>& gain) {
    int n = static_cast<int>(gain.size());
    int sum = 0;
    int result = 0;
    for (int i = 0; i < n; i++) {
      sum += gain[i];
      result = max(result, sum);
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> input = {-5,1,5,0,-7};
  int result = sol.largestAltitude(input);
  int result_expected = 1;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  input = {-4,-3,-2,-1,4,3,2};
  result = sol.largestAltitude(input);
  result_expected = 0;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}