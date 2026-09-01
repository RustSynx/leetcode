//
// Created by Milo on 9/1/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

class Solution {
 public:
  int minMoves(vector<string>& classroom, int energy) {
    int m = classroom.size();
    int n = classroom[0].length();
    int l_count = 0;
    vector<vector<int>> l_id(m, vector<int>(n, -1));
    pair<int, int> start = {-1, -1};
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (classroom[i][j] == 'S') {
          start = {i, j};
        }
        if (classroom[i][j] == 'L') {
          l_id[i][j] = l_count++;
        }
      }
    }
    vector<vector<vector<int>>> visited(m, vector<vector<int>>(n, vector<int>(1 << l_count, -1)));
    visited[start.first][start.second][0] = energy;
    queue<tuple<int, int, int,  int, int>> q;
    q.push({start.first, start.second, energy, 0, 0});
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};
    int target_mask = (1 << l_count) - 1;

    while (!q.empty()) {
      auto [x, y, e, mask, dist] = q.front();
      q.pop();

      if (mask == target_mask) {
        return dist;
      }

      for (int i = 0; i < 4; i++) {
        int nx = x + dr[i];
        int ny = y + dc[i];
        if (nx < 0 || ny < 0 || nx >= m || ny >= n || classroom[nx][ny] == 'X') {
          continue;
        }
        int next_e = e - 1;
        if (next_e < 0) continue;
        if (classroom[nx][ny] == 'R') {
          next_e = energy;
        }
        int next_m = mask;
        if (classroom[nx][ny] == 'L') {
          next_m |= 1 << l_id[nx][ny];
        }
        if (visited[nx][ny][next_m] < next_e) {
          visited[nx][ny][next_m] = next_e;
          q.push({nx, ny, next_e, next_m, dist + 1});
        }
      }
    }
    return -1;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<string> classroom = {"S.", "XL"};
  int result = sol.minMoves(classroom, 2);
  int result_expected = 2;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  classroom = {"LS", "RL"};
  result = sol.minMoves(classroom, 4);
  result_expected = 3;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  classroom = {"L.S", "RXL"};
  result = sol.minMoves(classroom, 3);
  result_expected = -1;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}