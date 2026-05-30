//
// Created by Milo on 5/30/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

struct Node {
  int max_space;
  int left_space;
  int right_space;
  bool obstacle;
};

class Tree {
 public:
  vector<Node> tree;
  Tree(int max_val) {
    tree.resize(max_val * 4);
    build(1, 0, max_val - 1);
  }
  void build(int node, int start, int end) {
    if (start == end) {
      if (start % 2 == 0) {
        tree[node] = {0, 0, 0, false};
      } else {
        tree[node] = {1, 1, 1, false};
      }
      return;
    }
    int mid = start + (end - start) / 2;
    build(node * 2, start, mid);
    build(node * 2 + 1, mid + 1, end);
    tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
  }
  Node merge(Node left_node, Node right_node) {
    Node parent;

    parent.obstacle = left_node.obstacle || right_node.obstacle;

    parent.max_space = max({left_node.max_space, right_node.max_space,
                            left_node.right_space + right_node.left_space});
    parent.left_space = left_node.obstacle
                            ? left_node.left_space
                            : left_node.max_space + right_node.left_space;
    parent.right_space = right_node.obstacle
                             ? right_node.right_space
                             : left_node.right_space + right_node.max_space;

    return parent;
  }
  void insertObstacle(int node, int start, int end, int x) {
    if (start == end) {
      tree[node].obstacle = true;
      return;
    }
    int mid = start + (end - start) / 2;
    if (x <= mid) {
      insertObstacle(node * 2, start, mid, x);
    } else {
      insertObstacle(node * 2 + 1, mid + 1, end, x);
    }
    tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
  }
  Node findNode(int node, int start, int end, int left_node, int right_node) {
    if (left_node <= start && end <= right_node) {
      return tree[node];
    }
    if (start == end) return tree[node];
    int mid = start + (end - start) / 2;
    if (right_node <= mid) {
      return findNode(node * 2, start, mid, left_node, right_node);
    }
    if (left_node > mid) {
      return findNode(node * 2 + 1, mid + 1, end, left_node, right_node);
    }
    return merge(findNode(node * 2, start, mid, left_node, right_node),
                 findNode(node * 2 + 1, mid + 1, end, left_node, right_node));
  }
};

class Solution {
 public:
  vector<bool> getResults(vector<vector<int>>& queries) {
    int max_val = 0;
    for (vector<int>& query : queries) {
      max_val = max(max_val, query[1]);
    }
    max_val = max_val * 2 + 1;
    Tree tree(max_val);
    vector<bool> result;
    for (vector<int>& query : queries) {
      if (query[0] == 1) {
        tree.insertObstacle(1, 0, max_val - 1, query[1] * 2);
      } else {
        Node node = tree.findNode(1, 0, max_val - 1, 0, query[1] * 2);
        result.push_back(node.max_space >= query[2]);
      }
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<vector<int>> queries = {{1, 2}, {2, 3, 3}, {2, 3, 1}, {2, 2, 2}};
  vector<bool> result = sol.getResults(queries);
  vector<bool> result_expected = {false, true, true};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  queries = {{1, 7}, {2, 7, 6}, {1, 2}, {2, 7, 5}, {2, 7, 6}};
  result = sol.getResults(queries);
  result_expected = {true, true, false};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}