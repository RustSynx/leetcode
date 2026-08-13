//
// Created by Milo on 8/13/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node {
  int size;
  int max_len;
  int left_len;
  int right_len;
  char left_char;
  char right_char;
};

class SegmentTree {
 public:
  vector<Node> tree;
  SegmentTree(int array_size) : tree(4 * array_size) {}

  Node merge(Node left, Node right) {
    Node node = Node();
    node.size = left.size + right.size;
    node.left_len = left.left_len;
    node.right_len = right.right_len;
    node.left_char = left.left_char;
    node.right_char = right.right_char;
    node.max_len = max(left.max_len, right.max_len);

    if (left.right_char == right.left_char) {
      node.max_len = max(node.max_len, left.right_len + right.left_len);
    }

    if (left.left_len == left.size && left.left_char == right.left_char) {
      node.left_len += right.left_len;
    }

    if (right.right_len == right.size && left.right_char == right.right_char) {
      node.right_len += left.right_len;
    }

    return node;
  }

  void build(const string& s, int node, int start, int end) {
    if (start == end) {
      tree[node] = Node{1, 1, 1, 1, s[start], s[start]};
      return;
    }

    int mid = start + (end - start) / 2;
    build(s, node * 2, start, mid);
    build(s, node * 2 + 1, mid + 1, end);

    tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
  }

  void update(int node, int start, int end, int idx, char c) {
    if (start == end) {
      tree[node] = Node{1, 1, 1, 1, c, c};
      return;
    }

    int mid = start + (end - start) / 2;
    if (start <= idx && idx <= mid) {
      update(node * 2, start, mid, idx, c);
    } else {
      update(node * 2 + 1, mid + 1, end, idx, c);
    }
    tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
  }
};

class Solution {
 public:
  vector<int> longestRepeating(string s, string queryCharacters,
                               vector<int>& queryIndices) {
    int sn = s.length();
    int qn = queryCharacters.length();
    SegmentTree tree(sn);
    tree.build(s, 1, 0, sn - 1);

    vector<int> result(qn);
    for (int i = 0; i < qn; i++) {
      int idx = queryIndices[i];
      char c = queryCharacters[i];
      tree.update(1, 0, sn - 1, idx, c);
      result[i] = tree.tree[1].max_len;
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> queryIndices = {1, 3, 3};
  vector<int> result = sol.longestRepeating("babacc", "bcb", queryIndices);
  vector<int> result_expected = {3, 3, 4};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  queryIndices = {2, 1};
  result = sol.longestRepeating("abyzz", "aa", queryIndices);
  result_expected = {2, 3};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}