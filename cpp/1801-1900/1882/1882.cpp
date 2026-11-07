//
// Created by Milo on 11/7/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
 public:
  vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
    int n = servers.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        free_s;
    using task_t = pair<long long, pair<int, int>>;
    priority_queue<task_t, vector<task_t>, greater<task_t>> busy_s;
    for (int i = 0; i < n; i++) {
      free_s.push({servers[i], i});
    }
    int t_n = tasks.size();
    vector<int> result(t_n);
    long long current_t = 0;
    for (int i = 0; i < t_n; i++) {
      current_t = max(current_t, static_cast<long long>(i));
      if (free_s.empty()) {
        current_t = busy_s.top().first;
      }
      while (!busy_s.empty() && busy_s.top().first <= current_t) {
        free_s.push(busy_s.top().second);
        busy_s.pop();
      }
      auto& [w, id] = free_s.top();
      result[i] = id;
      busy_s.push({current_t + tasks[i], free_s.top()});
      free_s.pop();
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> servers = {3, 3, 2};
  vector<int> tasks = {1, 2, 3, 2, 1, 2};
  vector<int> result = sol.assignTasks(servers, tasks);
  vector<int> result_expected = {2, 2, 0, 2, 1, 2};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  servers = {5, 1, 4, 3, 2};
  tasks = {2, 1, 2, 4, 5, 2, 1};
  result = sol.assignTasks(servers, tasks);
  result_expected = {1, 4, 1, 4, 1, 3, 2};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}