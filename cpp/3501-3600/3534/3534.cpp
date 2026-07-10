//
// Created by Milo on 7/10/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                   vector<vector<int>>& queries) {
    vector<pair<int,int>> nodes(n);
    for (int i = 0; i < n; i++) {
      nodes[i] = make_pair(i, nums[i]);
    }
    ranges::sort(nodes, [](const auto& a, const auto& b) {
      return a.second < b.second;
    });
    int logN = log2(n) + 1;
    vector sparse_table(logN, vector<int>(n));
    vector<int> origin_pos(n);
    int end = 0;
    for (int i = 0; i < n; i++) {
      while (end < n && nodes[end].second - nodes[i].second <= maxDiff) {
        end++;
      }
      sparse_table[0][i] = end - 1;
      origin_pos[nodes[i].first] = i;
    }
    for (int i = 1; i < logN; i++) {
      for (int j = 0; j < n; j++) {
        sparse_table[i][j] = sparse_table[i - 1][sparse_table[i - 1][j]];
      }
    }
    vector<int> result;
    result.reserve(queries.size());
    for (const auto& q: queries) {
      int u = origin_pos[q[0]];
      int v = origin_pos[q[1]];

      if (u > v) swap(u, v);

      if (u == v) {
        result.push_back(0);
        continue;
      }

      int dist = 0;
      int curr = u;
      for (int i = logN - 1; i >=0; i--) {
        if (sparse_table[i][curr] < v) {
          dist += (1 << i);
          curr = sparse_table[i][curr];
        }
      }
      if (sparse_table[0][curr] >= v) {
        result.push_back(dist + 1);
      } else {
        result.push_back(-1);
      }
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> nums = {1, 8, 3, 4, 2};
  vector<vector<int>> queries = {{0, 3}, {2, 4}};
  vector<int> result = sol.pathExistenceQueries(5, nums, 3, queries);
  vector<int> result_expected = {1, 1};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums = {5,3,1,9,10};
  queries = {{0, 1}, {0, 2}, {2, 3}, {4, 3}};
  result = sol.pathExistenceQueries(5, nums, 2, queries);
  result_expected = {1, 2, -1, 1};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}