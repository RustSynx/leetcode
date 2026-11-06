//
// Created by Milo on 11/6/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> countServers(int n, vector<vector<int>>& logs, int x,
                           vector<int>& queries) {
    int q_n = queries.size();
    vector<pair<int, int>> q_p(q_n);
    for (int i = 0; i < q_n; i++) {
      q_p[i] = {queries[i], i};
    }
    ranges::sort(q_p);
    ranges::sort(logs, [](const vector<int>& a, const vector<int>& b) {
      return a[1] < b[1];
    });
    vector<int> server_cnt(n + 1);
    int act_server = 0;
    vector<int> result(q_n);
    int right = 0;
    int left = 0;
    int l_n = logs.size();
    for (auto& [q, i] : q_p) {
      int start = q - x;
      while (right < l_n && logs[right][1] <= q) {
        int id = logs[right][0];
        if (server_cnt[id] == 0) {
          act_server++;
        }
        server_cnt[id]++;
        right++;
      }

      while (left < l_n && logs[left][1] < start) {
        int id = logs[left][0];
        if (server_cnt[id] == 1) {
          act_server--;
        }
        server_cnt[id]--;
        left++;
      }
      result[i] = n - act_server;
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<vector<int>> logs = {{1, 3}, {2, 6}, {1, 5}};
  vector<int> queries = {10, 11};
  vector<int> result = sol.countServers(3, logs, 5, queries);
  vector<int> result_expected = {1, 2};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  logs = {{2, 4}, {2, 1}, {1, 2}, {3, 1}};
  queries = {3, 4};
  result = sol.countServers(3, logs, 2, queries);
  result_expected = {0, 1};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}