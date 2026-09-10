//
// Created by Milo on 9/10/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

void delete_tree_node(TreeNode *root) {
  if (!root) return;
  delete_tree_node(root->left);
  delete_tree_node(root->right);
  delete root;
}

class Solution {
 public:
  int resultCount;

  int averageOfSubtree(TreeNode *root) {
    resultCount = 0;
    dfs(root);
    return resultCount;
  }

  pair<int, int> dfs(TreeNode *node) {
    if (node == nullptr) {
      return {0, 0};
    }

    auto left = dfs(node->left);
    auto right = dfs(node->right);

    int currentSum = left.first + right.first + node->val;
    int currentCount = left.second + right.second + 1;

    if (currentSum / currentCount == node->val) {
      resultCount++;
    }

    return {currentSum, currentCount};
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  TreeNode *root =
      new TreeNode(4, new TreeNode(8, new TreeNode(0), new TreeNode(1)),
                   new TreeNode(5, nullptr, new TreeNode(6)));
  int result = sol.averageOfSubtree(root);
  int result_expected = 5;
  assert(result == result_expected);
  cout << "PASSED" << endl;
  delete_tree_node(root);

  // Test Case 2
  cout << "Test Case 2: " << endl;
  root = new TreeNode(1);
  result = sol.averageOfSubtree(root);
  result_expected = 1;
  assert(result == result_expected);
  cout << "PASSED" << endl;
  delete_tree_node(root);

  return 0;
}