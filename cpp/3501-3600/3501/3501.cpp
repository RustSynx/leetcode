//
// Created by Milo on 7/22/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>
#include <string>

using namespace std;

class Solution {
 public:
  vector<int> maxActiveSectionsAfterTrade(string s,
                                          vector<vector<int>>& queries) {
    int n = s.length();
    int total_one = 0;
    int curr_zero_len = 0;
    vector<tuple<int, int, int>> zero_blocks;
    int start = 0;
    for (int i = 0; i < n; i++) {
      char c = s[i];
      if (c == '1') {
        total_one++;
      } else {
        if (curr_zero_len == 0) start = i;
        curr_zero_len++;
      }
      if ((i == n - 1 || s[i + 1] == '1') && curr_zero_len > 0) {
        zero_blocks.push_back({start, i, curr_zero_len});
        curr_zero_len = 0;
      }
    }

    vector<int> max_zero_blocks;
    for (int i = 0; i + 1 < zero_blocks.size(); i++) {
      max_zero_blocks.push_back(std::get<2>(zero_blocks[i]) +
                                std::get<2>(zero_blocks[i + 1]));
    }

    int mzb_len = max_zero_blocks.size();
    int st_log = 20;
    vector<vector<int>> st;
    if (mzb_len > 0) {
      st.assign(mzb_len, vector<int>(st_log, 0));
      for (int i = 0; i < mzb_len; i++) st[i][0] = max_zero_blocks[i];
      for (int j = 1; j < st_log; j++) {
        for (int i = 0; i + (1 << j) <= mzb_len; i++) {
          st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
      }
    }

    auto query_st = [&](int start, int end) {
      if (start > end || start < 0 || end >= mzb_len) return 0;
      int j = log2(end - start + 1);
      return max(st[start][j], st[end - (1 << j) + 1][j]);
    };

    auto get_overlap = [&](int idx, int start, int end) {
      return max(0, min(end, get<1>(zero_blocks[idx])) - max(start, get<0>(zero_blocks[idx])) + 1);
    };


    vector<int> result;
    result.reserve(queries.size());
    for (const auto& q : queries) {
      int start = q[0];
      int end = q[1];
      auto start_it = lower_bound(
          zero_blocks.begin(), zero_blocks.end(), start,
          [](const auto& a, int b) { return get<1>(a) < b; });
      auto end_it = upper_bound(
          zero_blocks.begin(), zero_blocks.end(), end,
          [](int b, const auto& a) { return b < get<0>(a); });
      int start_idx = -1, end_idx = -1;
      if (start_it != zero_blocks.end() && get<0>(*start_it) <= end) start_idx = start_it - zero_blocks.begin();
      if (end_it != zero_blocks.begin()) {
        auto prev_it = prev(end_it);
        if (get<1>(*prev_it) >= start) end_idx = prev_it - zero_blocks.begin();
      }

      int max_gain = 0;

      if (start_idx != -1 && end_idx != -1 && start_idx < end_idx) {
        if (end_idx == start_idx + 1) {
          max_gain = get_overlap(start_idx, start, end) + get_overlap(end_idx, start, end);
        } else {
          int gain_left = get_overlap(start_idx, start, end) + get<2>(zero_blocks[start_idx + 1]);
          int gain_right = get<2>(zero_blocks[end_idx - 1]) + get_overlap(end_idx, start, end);
          int gain_mid = query_st(start_idx + 1, end_idx - 2);
          max_gain = max({gain_left, gain_right, gain_mid});
        }
      }

      result.push_back(total_one + max_gain);
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<vector<int>> queries = {{0, 1}};
  vector<int> result = sol.maxActiveSectionsAfterTrade("01", queries);
  vector<int> result_expected = {1};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  queries = {{0, 3}, {0, 2}, {1, 3}, {2, 3}};
  result = sol.maxActiveSectionsAfterTrade("0100", queries);
  result_expected = {4, 3, 1, 1};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  queries = {{1, 5}, {0, 6}, {0, 4}};
  result = sol.maxActiveSectionsAfterTrade("1000100", queries);
  result_expected = {6, 7, 2};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 4
  cout << "Test Case 4: " << endl;
  queries = {{0, 3}, {1, 4}, {1, 3}};
  result = sol.maxActiveSectionsAfterTrade("01010", queries);
  result_expected = {4, 4, 2};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}