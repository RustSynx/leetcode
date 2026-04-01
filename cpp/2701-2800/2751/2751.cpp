//
// Created by Milo on 4/1/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

struct Robot {
  int id;
  int pos;
  int health;
  char dir;
};

class Solution {
 public:
  vector<int> survivedRobotsHealths(vector<int>& positions,
                                    vector<int>& healths, string directions) {
    int n = static_cast<int>(positions.size());
    vector<Robot> robots;
    robots.reserve(n);
    for (int i = 0; i < n; i++) {
      robots.push_back({i, positions[i], healths[i], directions[i]});
    }
    sort(robots.begin(), robots.end(), [](const Robot& a, const Robot& b) {
            return a.pos < b.pos;
        });
    vector<Robot> robot_stack;
    for (auto& robot : robots) {
      if (robot.dir == 'R') {
        robot_stack.push_back(robot);
      } else {
        bool survived = true;
        while (!robot_stack.empty() && robot_stack.back().dir == 'R') {
          if (robot_stack.back().health < robot.health) {
            robot_stack.pop_back();
            robot.health--;
          } else if (robot_stack.back().health == robot.health) {
            robot_stack.pop_back();
            survived = false;
            break;
          } else {
            robot_stack.back().health--;
            survived = false;
            break;
          }
        }
        if (survived) {
          robot_stack.push_back(robot);
        }
      }
    }
    sort(robot_stack.begin(), robot_stack.end(), [](const Robot& a, const Robot& b) {
        return a.id < b.id;
    });
    vector<int> result;
    for (const auto& robot : robot_stack) {
      result.push_back(robot.health);
    }

    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> positions = {5, 4, 3, 2, 1};
  vector<int> healths = {2, 17, 9, 15, 10};
  string directions = "RRRRR";
  vector<int> result =
      sol.survivedRobotsHealths(positions, healths, directions);
  vector<int> result_expected = {2, 17, 9, 15, 10};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  positions = {3, 5, 2, 6};
  healths = {10, 10, 15, 12};
  directions = "RLRL";
  result = sol.survivedRobotsHealths(positions, healths, directions);
  result_expected = {14};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  positions = {1, 2, 5, 6};
  healths = {10, 10, 11, 11};
  directions = "RLRL";
  result = sol.survivedRobotsHealths(positions, healths, directions);
  result_expected = {};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}