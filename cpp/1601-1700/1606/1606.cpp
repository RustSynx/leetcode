//
// Created by Milo on 11/9/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

class Solution {
 public:
  vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
    vector<int> servers(k);
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        busy_server;
    set<int> free_server;
    for (int i = 0; i < k; i++) {
      free_server.insert(i);
    }
    for (int i = 0; i < load.size(); i++) {
      int curr_time = arrival[i];
      while (!busy_server.empty() && busy_server.top().first <= curr_time) {
        free_server.insert(busy_server.top().second);
        busy_server.pop();
      }
      if (free_server.empty()) continue;
      auto it = free_server.lower_bound(i % k);
      int server_id;
      if (it != free_server.end()) {
        server_id =  *it;
      } else {
        server_id = *free_server.begin();
      }
      busy_server.push({curr_time + load[i], server_id});
      free_server.erase(server_id);
      servers[server_id]++;
    }
    int max_val = *ranges::max_element(servers);
    vector<int> result;
    for (int i = 0; i < k; i++) {
      if (servers[i] == max_val) result.push_back(i);
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> arrival = {1, 2, 3, 4, 5};
  vector<int> load = {5, 2, 3, 3, 3};
  vector<int> result = sol.busiestServers(3, arrival, load);
  vector<int> result_expected = {1};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  arrival = {1, 2, 3, 4};
  load = {1, 2, 1, 2};
  result = sol.busiestServers(3, arrival, load);
  result_expected = {0};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  arrival = {1, 2, 3};
  load = {10, 12, 11};
  result = sol.busiestServers(3, arrival, load);
  result_expected = {0, 1, 2};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}