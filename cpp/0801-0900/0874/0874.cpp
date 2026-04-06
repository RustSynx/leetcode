//
// Created by Milo on 4/6/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
 public:
  int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
    unordered_map<int, unordered_set<int>> obstacle_map;
    unordered_map<int, vector<int>> directions = {
        {0, {1, 1}},
        {90, {1, 0}},
        {180, {-1, 1}},
        {270, {-1, 0}},
    };
    for (int i = 0; i < obstacles.size(); i++) {
      obstacle_map[obstacles[i][0]].insert(obstacles[i][1]);
    }
    vector<int> result_xy(2, 0);
    int result = 0;
    int current_direction = 0;
    for (int n : commands) {
      if (n == -1) {
        current_direction =
            current_direction + 90 >= 360 ? 0 : current_direction + 90;
      } else if (n == -2) {
        current_direction =
            current_direction - 90 < 0 ? 270 : current_direction - 90;
      } else {
        int direction_sign = directions[current_direction][0];
        int direction = directions[current_direction][1];
        int current_x = result_xy[0];
        int current_y = result_xy[1];
        for (int i = 0; i < n; i++) {
          if (direction == 0) {
            current_x += 1 * direction_sign;
            result_xy[0] = current_x;
            if (obstacle_map.contains(current_x) &&
                obstacle_map[current_x].contains(current_y)) {
              current_x += 1 * direction_sign * -1;
              result_xy[0] = current_x;
              break;
            }
          } else {
            current_y += 1 * direction_sign;
            result_xy[1] = current_y;
            if (obstacle_map.contains(current_x) &&
                obstacle_map[current_x].contains(current_y)) {
              current_y += 1 * direction_sign * -1;
              result_xy[1] = current_y;
              break;
            }
          }
        }
        result = max(result,
                     result_xy[0] * result_xy[0] + result_xy[1] * result_xy[1]);
      }
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> commands = {4, -1, 3};
  vector<vector<int>> obstacles = {};
  int result = sol.robotSim(commands, obstacles);
  int result_expected = 25;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  commands = {4, -1, 4, -2, 4};
  obstacles = {{2, 4}};
  result = sol.robotSim(commands, obstacles);
  result_expected = 65;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  commands = {6, -1, -1, 6};
  obstacles = {{0, 0}};
  result = sol.robotSim(commands, obstacles);
  result_expected = 36;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}