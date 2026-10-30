//
// Created by Milo on 10/30/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

class Solution {
 public:
  int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
    vector<vector<pair<int, int>>> nodes(n);
    for (vector<int>& e : edges) {
      nodes[e[0]].push_back({e[2], e[1]});
    }
    vector<vector<int>> min_w(n, vector<int>(k + 1, INT_MAX));
    min_w[0][1] = 0;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                   greater<tuple<int, int, int>>>
        pq;
    pq.push({0, 0, 1});
    while (!pq.empty()) {
      auto [w, n_n, count] = pq.top();
      pq.pop();
      if (n_n == n - 1) return w;
      if (w > min_w[n_n][count]) continue;
      int p_l = labels[n_n];
      for (pair<int, int>& p : nodes[n_n]) {
        int n_w = w + p.first;
        int n_count = p_l == labels[p.second] ? count + 1 : 1;
        if (n_count <= k && n_w < min_w[p.second][n_count]) {
          min_w[p.second][n_count] = n_w;
          pq.push({n_w, p.second, n_count});
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
  vector<vector<int>> edges = {{0, 1, 1}, {1, 2, 1}, {0, 2, 3}};
  int result = sol.shortestPath(3, edges, "aab", 1);
  int result_expected = 3;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  edges = {{0, 1, 1}, {1, 2, 1}, {0, 2, 3}};
  result = sol.shortestPath(3, edges, "aab", 2);
  result_expected = 2;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  edges = {{0, 1, 1}, {1, 2, 1}};
  result = sol.shortestPath(3, edges, "aaa", 2);
  result_expected = -1;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}