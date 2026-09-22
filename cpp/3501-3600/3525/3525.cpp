//
// Created by Milo on 9/22/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

struct Node {
  int total_mod = 0;
  int count_mod[5] = {};
};

class SegmentTree {
 public:
  vector<Node> tree;
  int k;
  SegmentTree(int array_size, int mod) : tree(4 * array_size), k(mod) {}

  Node merge(Node left, Node right) {
    Node node = Node();
    node.total_mod = left.total_mod * right.total_mod % k;
    for (int i = 0; i < k; i++) {
      node.count_mod[i] += left.count_mod[i];
    }
    for (int i = 0; i < k; i++) {
      int new_mod = (left.total_mod * i) % k;
      node.count_mod[new_mod] += right.count_mod[i];
    }
    return node;
  }

  void build(const vector<int>& nums, int node, int start, int end) {
    if (start == end) {
      int mod = nums[start] % k;
      Node new_node = Node();
      new_node.total_mod = mod;
      new_node.count_mod[mod] = 1;
      tree[node] = new_node;
      return;
    }
    int mid = start + (end - start) / 2;
    build(nums, node * 2, start, mid);
    build(nums, node * 2 + 1, mid + 1, end);
    tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
  }

  void update(const vector<int>& nums, int node, int start, int end, int idx) {
    if (start == end) {
      int mod = nums[start] % k;
      Node new_node = Node();
      new_node.total_mod = mod;
      new_node.count_mod[mod] = 1;
      tree[node] = new_node;
      return;
    }
    int mid = start + (end - start) / 2;
    if (start <= idx && idx <= mid) {
      update(nums, node * 2, start, mid, idx);
    } else {
      update(nums, node * 2 + 1, mid + 1, end, idx);
    }
    tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
  }

  Node query(int node, int start, int end, int left, int right) {
    if (right < start || end < left) {
      Node empty_node = Node();
      empty_node.total_mod = 1;
      return empty_node;
    }
    if (left <= start && end <= right) {
      return tree[node];
    }
    int mid = start + (end - start) / 2;
    Node left_result = query(node * 2, start, mid, left, right);
    Node right_result = query(node * 2 + 1, mid + 1, end, left, right);
    return merge(left_result, right_result);
  }
};

class Solution {
 public:
  vector<int> resultArray(vector<int>& nums, int k,
                          vector<vector<int>>& queries) {
    int n = nums.size();
    SegmentTree tree(n, k);
    tree.build(nums, 1, 0, n - 1);
    vector<int> result;
    for (const auto& q : queries) {
      int index = q[0];
      int value = q[1];
      int start = q[2];
      int x = q[3];
      nums[index] = value;
      tree.update(nums, 1, 0, n - 1, index);
      Node res = tree.query(1, 0, n - 1, start, n - 1);
      result.push_back(res.count_mod[x]);
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> nums = {1, 2, 3, 4, 5};
  vector<vector<int>> queries = {{2, 2, 0, 2}, {3, 3, 3, 0}, {0, 1, 0, 1}};
  vector<int> result = sol.resultArray(nums, 3, queries);
  vector<int> result_expected = {2, 2, 2};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums = {1, 2, 4, 8, 16, 32};
  queries = {{0, 2, 0, 2}, {0, 2, 0, 1}};
  result = sol.resultArray(nums, 4, queries);
  result_expected = {1, 0};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  nums = {1, 1, 2, 1, 1};
  queries = {{2, 1, 0, 1}};
  result = sol.resultArray(nums, 2, queries);
  result_expected = {5};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}