//
// Created by Milo on 7/3/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution {
 public:
  int n;
  int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online,
                       long long k) {
    n = online.size();
    vector<vector<pair<int, int>>> connect(n);
    int max_cost = 0;
    for (const vector<int>& edge : edges) {
      if (online[edge[0]] && online[edge[1]]) {
        connect[edge[0]].push_back({edge[1], edge[2]});
        max_cost = max(max_cost, edge[2]);
      }
    }
    int min_cost = 0;
    int result = -1;
    while (min_cost <= max_cost) {
      int mid = min_cost + (max_cost - min_cost) / 2;
      if (isPossible(connect, mid, k)) {
        result = mid;
        min_cost = mid + 1;
      } else {
        max_cost = mid - 1;
      }
    }
    return result;
  }
  bool isPossible(vector<vector<pair<int,int>>>& connect, int mid, long long k) {
    vector dist(n, LLONG_MAX);
    dist[0] = 0;

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, 0});

    while (!pq.empty()) {
      auto [curr_cost, curr_node] = pq.top();
      pq.pop();
      if (curr_cost > dist[curr_node]) continue;

      if (curr_node == n - 1) {
        return curr_cost <= k;
      }

      for (const auto& p : connect[curr_node]) {
        int next_node = p.first;
        long long edge_cost = p.second;
        long long next_cost = curr_cost + edge_cost;

        if (next_cost > k || edge_cost < mid) continue;

        if (next_cost < dist[next_node]) {
          dist[next_node] = next_cost;
          pq.push({next_cost, next_node});
        }
      }
    }
    return dist[n - 1] <= k;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<vector<int>> edges = {{0, 1, 5}, {1, 3, 10}, {0, 2, 3}, {2, 3, 4}};
  vector online = {true, true, true, true};
  int result = sol.findMaxPathScore(edges, online, 10);
  int result_expected = 3;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  edges = {{0, 1, 7}, {1, 4, 5}, {0, 2, 6}, {2, 3, 6}, {3, 4, 2}, {2, 4, 6}};
  online = {true, true, true, false, true};
  result = sol.findMaxPathScore(edges, online, 12);
  result_expected = 6;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}