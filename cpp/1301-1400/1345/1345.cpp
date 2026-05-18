//
// Created by Milo on 5/18/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int minJumps(vector<int>& arr) {
    int n = static_cast<int>(arr.size());
    if (n == 1) return 0;
    unordered_map<int, vector<int>> jump_position;
    for (int i = 0; i < n; i++) {
      jump_position[arr[i]].push_back(i);
    }
    queue<pair<int, int>> idx_q;
    idx_q.push({0, 0});
    vector<bool> visited(n, false);
    visited[0] = true;
    while (!idx_q.empty()) {
      auto [curr_idx, cnt] = idx_q.front();
      idx_q.pop();
      if (curr_idx == n - 1) return cnt;
      if (jump_position.contains(arr[curr_idx])) {
        for (int i = 0; i < jump_position[arr[curr_idx]].size(); i++) {
          if (jump_position[arr[curr_idx]][i] != curr_idx && !visited[jump_position[arr[curr_idx]][i]]) {
            idx_q.push({jump_position[arr[curr_idx]][i], cnt + 1});
            visited[jump_position[arr[curr_idx]][i]] = true;
          }
        }
        jump_position[arr[curr_idx]].clear();
      }
      if (curr_idx - 1 >= 0 && !visited[curr_idx - 1]) {
        idx_q.push({curr_idx - 1, cnt + 1});
        visited[curr_idx - 1] = true;
      }
      if (curr_idx + 1 < n && !visited[curr_idx + 1]) {
        idx_q.push({curr_idx + 1, cnt + 1});
        visited[curr_idx + 1] = true;
      }
    }
    return 0;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> arr = {100, -23, -23, 404, 100, 23, 23, 23, 3, 404};
  int result = sol.minJumps(arr);
  int result_expected = 3;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  arr = {7};
  result = sol.minJumps(arr);
  result_expected = 0;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  arr = {7, 6, 9, 6, 9, 6, 9, 7};
  result = sol.minJumps(arr);
  result_expected = 1;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}