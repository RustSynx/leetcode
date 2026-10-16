//
// Created by Milo on 10/16/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class SegmentTree {
 public:
  int n;
  int mod = 1e9 + 7;
  vector<long long> tree_sq;
  vector<long long> tree_sum;
  vector<long long> lazy;
  SegmentTree(int array_size)
      : n(array_size),
        tree_sq(4 * array_size),
        tree_sum(4 * array_size),
        lazy(4 * array_size) {}

  void add(int l, int r, long long v) {
    if (l <= r) {
      update(1, 0, n - 1, l, r, v);
    }
  }

  long long query() { return tree_sq[1]; }

  void push_down(int node, int start, int end) {
    if (lazy[node] != 0) {
      int mid = start + (end - start) / 2;
      long long v = lazy[node];
      apply(node * 2, v, mid - start + 1);
      apply(node * 2 + 1, v, end - mid);
      lazy[node] = 0;
    }
  }

  void update(int node, int start, int end, int l, int r, long long v) {
    if (r < start || end < l) return;
    if (l <= start && end <= r) {
      apply(node, v, end - start + 1);
      return;
    }
    push_down(node, start, end);
    int mid = start + (end - start) / 2;
    update(node * 2, start, mid, l, r, v);
    update(node * 2 + 1, mid + 1, end, l, r, v);
    tree_sq[node] = (tree_sq[node * 2] + tree_sq[node * 2 + 1]) % mod;
    tree_sum[node] = (tree_sum[node * 2] + tree_sum[node * 2 + 1]) % mod;
  }

  void apply(int node, long long v, long long len) {
    tree_sq[node] = (tree_sq[node] + 2 * v % mod * tree_sum[node] % mod + v * v % mod * len % mod) % mod;
    tree_sum[node] = (tree_sum[node] + v * len % mod) % mod;
    lazy[node] = (lazy[node] + v) % mod;
  }
};

class Solution {
 public:
  int sumCounts(vector<int>& nums) {
    int n = nums.size();
    int mod = 1e9 + 7;
    int result = 0;
    SegmentTree tree(n);
    int last_position[100001];
    memset(last_position, -1, sizeof(last_position));
    for (int i = 0; i < n; i++) {
      int num = nums[i];
      int left = last_position[num] + 1;
      tree.add(left, i, 1);
      result = (result + tree.query()) % mod;
      last_position[num] = i;
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> nums = {1, 2, 1};
  int result = sol.sumCounts(nums);
  int result_expected = 15;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums = {2, 2};
  result = sol.sumCounts(nums);
  result_expected = 3;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}