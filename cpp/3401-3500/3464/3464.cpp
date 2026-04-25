//
// Created by Milo on 4/25/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

struct Point {
  long long x;
  long long y;
  long long pos;
};

class Solution {
 public:
  int maxDistance(int side, vector<vector<int>>& points, int k) {
    int n = static_cast<int>(points.size());
    int high = 2 * side;
    int low = 0;
    int result = 0;
    vector<Point> point_vec(n);
    for (int i = 0; i < n; i++) {
      point_vec[i].x = points[i][0];
      point_vec[i].y = points[i][1];
      point_vec[i].pos = calcPos(points[i][0], points[i][1], side);
    }

    sort(point_vec.begin(), point_vec.end(), [](const Point& a, const Point& b) {
      return a.pos < b.pos;
    });
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (canExist(point_vec, k, mid)) {
        result = mid;
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    return result;
  }

  long long calcPos(int x, int y, int side) {
    if (x == 0) {
      return y;
    } else if (y == side) {
      return static_cast<long long>(side) + x;
    } else if (x == side) {
      return 3LL * side - y;
    } else {
      return 4LL * side - x;
    }
  }

  bool canExist(const vector<Point>& points, int k, int mid) {
    int n = static_cast<int>(points.size());
    vector<int> next_val(2 * n, 2 * n);
    int right = 0;
    for (int left = 0; left < n; ++left) {
      if (right <= left) right = left + 1;
      while (right < left + n) {
        long long dist = abs(points[left].x - points[right % n].x) + abs(points[left].y - points[right % n].y);
        if (dist >= mid) break;
        right++;
      }
      next_val[left] = right;
      next_val[left + n] = right + n;
    }

    for (int i = 0; i < n; i++) {
      int current = i;
      for (int count = 1; count < k; count++) {
        current = next_val[current];
        if (current >= i + n) break;
      }
      long long distance = abs(points[i].x - points[current % n].x) +
                 abs(points[i].y - points[current % n].y);
      if (current < i + n && distance >= mid) {
        return true;
      }
    }
    return false;
  }
};

int main() {
  Solution sol;
  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<vector<int>> points = {{0, 2}, {2, 0}, {2, 2}, {0, 0}};
  int result = sol.maxDistance(2, points, 4);
  int result_expected = 2;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  points = {{0, 0}, {1, 2}, {2, 0}, {2, 2}, {2, 1}};
  result = sol.maxDistance(2, points, 4);
  result_expected = 1;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  points = {{0, 0}, {0, 1}, {0, 2}, {1, 2}, {2, 0}, {2, 2}, {2, 1}};
  result = sol.maxDistance(2, points, 5);
  result_expected = 1;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}