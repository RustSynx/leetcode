//
// Created by Milo on 6/3/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
 public:
  int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration,
                         vector<int>& waterStartTime,
                         vector<int>& waterDuration) {
    int result = INT_MAX;
    int n = static_cast<int>(landStartTime.size());
    int m = static_cast<int>(waterStartTime.size());
    int land_finish = INT_MAX;
    for (int i = 0; i < n; i++) {
      land_finish = min(land_finish, landStartTime[i] + landDuration[i]);
    }
    int water_finish = INT_MAX;
    for (int i = 0; i < m; i++) {
      water_finish = min(water_finish, waterStartTime[i] + waterDuration[i]);
      result = min(result, max(land_finish, waterStartTime[i]) + waterDuration[i]);
    }
    for (int i = 0; i < n; i++) {
      result = min(result, max(water_finish, landStartTime[i]) + landDuration[i]);
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> landStartTime = {2, 8};
  vector<int> landDuration = {4, 1};
  vector<int> waterStartTime = {6};
  vector<int> waterDuration = {3};
  int result = sol.earliestFinishTime(landStartTime, landDuration,
                                      waterStartTime, waterDuration);
  int result_expected = 9;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  landStartTime = {5};
  landDuration = {3};
  waterStartTime = {1};
  waterDuration = {10};
  result = sol.earliestFinishTime(landStartTime, landDuration, waterStartTime,
                                  waterDuration);
  result_expected = 14;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}