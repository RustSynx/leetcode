//
// Created by Milo on 4/3/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

class Solution {
 public:
  int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
    int robot_count = static_cast<int>(robots.size());
    vector<pair<int, int>> robot_info(robot_count);
    for (int i = 0; i < robot_count; i++) {
      robot_info[i].first = robots[i];
      robot_info[i].second = distance[i];
    }
    sort(robot_info.begin(), robot_info.end(),
         [](pair<int, int> a, pair<int, int> b) { return a.first < b.first; });
    sort(walls.begin(), walls.end());
    vector<vector<int>> destroy_walls(robot_count, vector<int>(2, 0));
    for (int i = 0; i < robot_count; i++) {
      int left = i > 0 ? max(robot_info[i].first - robot_info[i].second,
                             robot_info[i - 1].first)
                       : robot_info[i].first - robot_info[i].second;
      destroy_walls[i][0] = count_walls(walls, left, robot_info[i].first);
      int right = i < robot_count - 1
                      ? min(robot_info[i].first + robot_info[i].second,
                            robot_info[i + 1].first)
                      : robot_info[i].first + robot_info[i].second;
      destroy_walls[i][1] = count_walls(walls, robot_info[i].first, right);
      if (i != 0) {
        int left_left = destroy_walls[i][0] + destroy_walls[i - 1][0];
        int left_right =
            destroy_walls[i][0] + destroy_walls[i - 1][1] -
            count_walls(walls, left,
                        min(robot_info[i - 1].first + robot_info[i - 1].second,
                            robot_info[i].first));
        if (left == robot_info[i - 1].first) {
          left_left -= count_walls(walls, left, left);
        }
        destroy_walls[i][0] = max(left_left, left_right);
        int right_left = destroy_walls[i][1] + destroy_walls[i - 1][0];
        int right_right = destroy_walls[i][1] + destroy_walls[i - 1][1];
        if (robot_info[i - 1].first + robot_info[i - 1].second >=
            robot_info[i].first) {
          right_right -=
              count_walls(walls, robot_info[i].first, robot_info[i].first);
        }
        destroy_walls[i][1] = max(right_right, right_left);
      }
    }
    return max(destroy_walls[destroy_walls.size() - 1][0],
               destroy_walls[destroy_walls.size() - 1][1]);
  }
  int count_walls(vector<int>& walls, int left, int right) {
    if (left > right) return 0;
    auto start_it = lower_bound(walls.begin(), walls.end(), left);
    auto end_it = upper_bound(walls.begin(), walls.end(), right);
    return static_cast<int>(std::distance(start_it, end_it));
  };
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> robots = {4};
  vector<int> distance = {3};
  vector<int> walls = {1, 10};
  int result = sol.maxWalls(robots, distance, walls);
  int result_expected = 1;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  robots = {10, 2};
  distance = {5, 1};
  walls = {5, 2, 7};
  result = sol.maxWalls(robots, distance, walls);
  result_expected = 3;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  robots = {1, 2};
  distance = {100, 1};
  walls = {10};
  result = sol.maxWalls(robots, distance, walls);
  result_expected = 0;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}