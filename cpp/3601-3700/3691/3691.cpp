//
// Created by Milo on 6/10/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  long long maxTotalValue(vector<int>& nums, int k) {
    int n = static_cast<int>(nums.size());
    int logN = log2(n) + 1;
    vector<vector<int>> max_table(n, vector<int>(logN));
    vector<vector<int>> min_table(n, vector<int>(logN));

    for (int i = 0; i < n; i++) {
      max_table[i][0] = nums[i];
      min_table[i][0] = nums[i];
    }

    for (int j = 1; j < logN; j++) {
      for (int i = 0; i + (1 << j) <= n; i++) {
        max_table[i][j] =
            max(max_table[i][j - 1], max_table[i + (1 << (j - 1))][j - 1]);
        min_table[i][j] =
            min(min_table[i][j - 1], min_table[i + (1 << (j - 1))][j - 1]);
      }
    }

    auto get_max_val = [&](int left, int right) {
      int j = log2(right - left + 1);
      int max_val = max(max_table[left][j], max_table[right - (1 << j) + 1][j]);
      int min_val = min(min_table[left][j], min_table[right - (1 << j) + 1][j]);
      return max_val - min_val;
    };

    auto make_hash = [](int left, int right) {
      return (static_cast<long long>(left) << 32) | right;
    };
    priority_queue<tuple<int, int, int>> pq;
    pq.push({get_max_val(0, n - 1), 0, n - 1});
    unordered_set<long long> visited;
    visited.insert(make_hash(0, n - 1));

    long long result = 0;
    while (k > 0 && !pq.empty()) {
      auto [max_val, l, r] = pq.top();
      pq.pop();
      result += max_val;
      k--;

      if (max_val == 0) break;

      if (!visited.contains(make_hash(l + 1, r))) {
        visited.insert(make_hash(l + 1, r));
        pq.push({get_max_val(l + 1, r), l + 1, r});
      }

      if (!visited.contains(make_hash(l, r - 1))) {
        visited.insert(make_hash(l, r - 1));
        pq.push({get_max_val(l, r - 1), l, r - 1});
      }
    }

    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> nums = {1, 3, 2};
  long long result = sol.maxTotalValue(nums, 2);
  long long result_expected = 4;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums = {4, 2, 5, 1};
  result = sol.maxTotalValue(nums, 3);
  result_expected = 12;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}