//
// Created by Milo on 4/7/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Robot {
 private:
  int width;
  int height;
  vector<int> pos;
  string dir;

 public:
  Robot(int width, int height)
      : width(width - 1), height(height - 1), pos({0, 0}), dir("East") {}

  void step(int num) {
    while (num > 0) {
      if (pos[0] == 0 && pos[1] == 0 && num > (width * 2 + height * 2)) {
        num %= (width * 2 + height * 2);
        dir = "South";
      }
      int x = pos[0];
      int y = pos[1];
      if (dir == "East") {
        int step = min(width - x, num);
        pos[0] += step;
        num -= step;
        if (num > 0) {
          changeDir();
        }
      } else if (dir == "West") {
        int step = min(x, num);
        pos[0] -= step;
        num -= step;
        if (num > 0) {
          changeDir();
        }
      } else if (dir == "North") {
        int step = min(height - y, num);
        pos[1] += step;
        num -= step;
        if (num > 0) {
          changeDir();
        }
      } else {
        int step = min(y, num);
        pos[1] -= step;
        num -= step;
        if (num > 0) {
          changeDir();
        }
      }
    }
  }

  vector<int> getPos() { return pos; }

  string getDir() { return dir; }

  void changeDir() {
    string currentDir = getDir();
    dir = currentDir == "East"    ? "North"
          : currentDir == "North" ? "West"
          : currentDir == "West"  ? "South"
                                  : "East";
  }
};

int main() {
  // Test Case 1
  cout << "Test Case 1: " << endl;
  Robot robot = Robot(6, 3);
  robot.step(2);
  robot.step(2);
  vector<int> resultGetPos = robot.getPos();
  vector<int> getPosExpected = {4, 0};
  assert(resultGetPos == getPosExpected);
  string resultGetDir = robot.getDir();
  string getDirExpected = "East";
  assert(resultGetDir == getDirExpected);
  robot.step(2);
  robot.step(1);
  robot.step(4);
  getPosExpected = {1, 2};
  resultGetPos = robot.getPos();
  assert(resultGetPos == getPosExpected);
  resultGetDir = robot.getDir();
  getDirExpected = "West";
  assert(resultGetDir == getDirExpected);
  cout << "PASSED" << endl;

  return 0;
}