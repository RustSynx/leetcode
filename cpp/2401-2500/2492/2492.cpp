//
// Created by Milo on 7/4/26.
//
#include <algorithm>
#include <cassert>
#include <queue>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int minScore(int n, vector<vector<int>>& roads) {
    vector<vector<pair<int, int>>> path(n + 1);
    vector<bool> visited(n + 1);
    queue<pair<int, int>> q;
    for (const vector<int>& road: roads) {
      path[road[0]].push_back(make_pair(road[1], road[2]));
      path[road[1]].push_back(make_pair(road[0], road[2]));
    }
    q.push({1, INT_MAX});
    int result = INT_MAX;
    while (!q.empty()) {
      auto [node, dist] = q.front();
      q.pop();
      result = min(result, dist);
      if (visited[node]) continue;
      visited[node] = true;
      for (const auto& p : path[node]) {
        q.push(p);
      }
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<vector<int>> roads = {{1, 2, 9}, {2, 3, 6}, {2, 4, 5}, {1, 4, 7}};
  int result = sol.minScore(4, roads);
  int result_expected = 5;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  roads = {{1, 2, 2}, {1, 3, 4}, {3, 4, 7}};
  result = sol.minScore(4, roads);
  result_expected = 2;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}