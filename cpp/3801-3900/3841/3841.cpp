//
// Created by Milo on 10/29/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int timer;
  vector<int> in_time, out_time, depth;
  vector<vector<int>> up;
  vector<int> bit;

  vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s,
                              vector<string>& queries) {
    timer = 0;
    in_time.assign(n, 0);
    out_time.assign(n, 0);
    depth.assign(n, 0);
    up.assign(n, vector<int>(20, -1));
    bit.assign(n + 2, 0);
    vector<vector<int>> adj(n);
    for (const auto& edge : edges) {
      adj[edge[0]].push_back(edge[1]);
      adj[edge[1]].push_back(edge[0]);
    }
    dfs(0, -1, 0, adj);
    for (int i = 0; i < n; i++) {
      int val = 1 << (s[i] - 'a');
      update_range(in_time[i], out_time[i], val);
    }
    vector<bool> result;
    for (const string& q : queries) {
      if (q[0] == 'u') {
        int space1 = q.find(' ');
        int space2 = q.rfind(' ');
        int u = stoi(q.substr(space1 + 1, space2 - space1 - 1));
        char c = q.back();
        int diff = (1 << (s[u] - 'a')) ^ (1 << (c - 'a'));
        update_range(in_time[u], out_time[u], diff);
        s[u] = c;
      } else {
        int space1 = q.find(' ');
        int space2 = q.rfind(' ');
        int u = stoi(q.substr(space1 + 1, space2 - space1 - 1));
        int v = stoi(q.substr(space2 + 1));
        int lca = get_lca(u, v);
        int mask_u = query_point(in_time[u]);
        int mask_v = query_point(in_time[v]);
        int mask_lca = 1 << (s[lca] - 'a');
        int path_mask = mask_u ^ mask_v ^ mask_lca;
        if (path_mask == 0 || (path_mask & (path_mask - 1)) == 0) {
          result.push_back(true);
        } else {
          result.push_back(false);
        }
      }
    }
    return result;
  }
  void dfs(int u, int p, int d, const vector<vector<int>>& adj) {
    timer++;
    in_time[u] = timer;
    depth[u] = d;
    up[u][0] = p;
    for (int i = 1; i < 20; i++) {
      if (up[u][i - 1] != -1) {
        up[u][i] = up[up[u][i - 1]][i - 1];
      } else {
        up[u][i] = -1;
      }
    }
    for (int v : adj[u]) {
      if (v != p) {
        dfs(v, u, d + 1, adj);
      }
    }
    out_time[u] = timer;
  }
  int get_lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    int diff = depth[u] - depth[v];
    for (int i = 0; i < 20; i++) {
      if ((diff >> i) & 1) {
        u = up[u][i];
      }
    }
    if (u == v) return u;
    for (int i = 19; i >= 0; i--) {
      if (up[u][i] != up[v][i]) {
        u = up[u][i];
        v = up[v][i];
      }
    }
    return up[u][0];
  }
  void update_bit(int idx, int val) {
    for (; idx < bit.size(); idx += idx & -idx) {
      bit[idx] ^= val;
    }
  }
  void update_range(int l, int r, int val) {
    update_bit(l, val);
    update_bit(r + 1, val);
  }
  int query_point(int idx) {
    int res = 0;
    for (; idx > 0; idx -= idx & -idx) {
      res ^= bit[idx];
    }
    return res;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<vector<int>> edges = {{0, 1}, {1, 2}};
  vector<string> queries = {"query 0 2", "update 1 b", "query 0 2"};
  vector<bool> result = sol.palindromePath(3, edges, "aac", queries);
  vector<bool> result_expected = {true, false};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  edges = {{0, 1}, {0, 2}, {0, 3}};
  queries = {"query 1 2", "update 0 b", "query 2 3", "update 3 a", "query 1 3"};
  result = sol.palindromePath(4, edges, "abca", queries);
  result_expected = {false, false, true};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}