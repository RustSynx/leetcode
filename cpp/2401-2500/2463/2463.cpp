//
// Created by Milo on 4/14/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

class Solution {
 public:
  long long memo[101][101];
  int m, n;
  long long minimumTotalDistance(vector<int>& robot,
                                 vector<vector<int>>& factory) {
    m = static_cast<int>(robot.size());
    n = static_cast<int>(factory.size());
    memset(memo, -1, sizeof(memo));
    sort(robot.begin(), robot.end());
    sort(factory.begin(), factory.end(),
         [](vector<int>& a, vector<int>& b) { return a[0] < b[0]; });
    return calcDistance(robot, factory, 0, 0);
  }
  long long calcDistance(vector<int>& robot, vector<vector<int>>& factory,
                         int current_robot_idx, int current_factory_idx) {
    if (current_robot_idx == m) return 0;
    if (current_factory_idx == n) return 1000000000000000LL;
    if (memo[current_robot_idx][current_factory_idx] != -1)
      return memo[current_robot_idx][current_factory_idx];
    long long distance = calcDistance(robot, factory, current_robot_idx,
                                      current_factory_idx + 1);
    long long current_distance = 0;
    int limit = factory[current_factory_idx][1];
    for (int i = 0; i < limit; i++) {
      if (current_robot_idx + i >= m) break;
      current_distance +=
          abs(robot[current_robot_idx + i] - factory[current_factory_idx][0]);
      distance = min(distance,
                     current_distance + calcDistance(robot, factory,
                                                     current_robot_idx + i + 1,
                                                     current_factory_idx + 1));
    }
    return memo[current_robot_idx][current_factory_idx] = distance;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> robot = {0, 4, 6};
  vector<vector<int>> factory = {{2, 2}, {6, 2}};
  long long result = sol.minimumTotalDistance(robot, factory);
  long long result_expected = 4;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  robot = {1, -1};
  factory = {{-2, 1}, {2, 1}};
  result = sol.minimumTotalDistance(robot, factory);
  result_expected = 2;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}