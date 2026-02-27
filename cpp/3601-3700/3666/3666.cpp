//
// Created by Milo on 2/27/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <deque>
#include <set>

using namespace std;

class Solution {
public:
  int minOperations(string s, int k) {
    int zero_count = 0;
    int string_length = s.size();
    for (char c : s) {
      if (c == '0') zero_count++;
    }

    set<int> unvisited_even, unvisited_odd;
    for (int i = 0; i <= string_length; i++) {
      if (i % 2 == 0) unvisited_even.insert(i);
      else unvisited_odd.insert(i);
    }

    deque<pair<int,int>> dq;
    dq.emplace_back(zero_count, 0);

    if (zero_count % 2 == 0) unvisited_even.erase(zero_count);
    else unvisited_odd.erase(zero_count);

    while (!dq.empty()) {
      auto [current_zero_count, depth] = dq.front();
      dq.pop_front();

      if (current_zero_count == 0) return depth;

      int min_change_zero = max(0, k - (string_length - current_zero_count));
      int max_change_zero = min(k, current_zero_count);

      int min_next = current_zero_count - max_change_zero + (k - max_change_zero);
      int max_next = current_zero_count - min_change_zero + (k - min_change_zero);

      set<int>& unvisited = (min_next % 2 == 0) ? unvisited_even : unvisited_odd;

      auto it = unvisited.lower_bound(min_next);
      while (it != unvisited.end() && *it <= max_next) {
        int next_zero_count = *it;
        dq.emplace_back(next_zero_count, depth + 1);

        it = unvisited.erase(it);
      }
    }
    return -1;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  int result = sol.minOperations("110", 1);
  int result_expected = 1;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.minOperations("0101", 3);
  result_expected = 2;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  result = sol.minOperations("101", 2);
  result_expected = -1;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}