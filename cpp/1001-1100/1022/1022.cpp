//
// Created by Milo on 2/24/26.
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

class Solution {
 public:
  int sumRootToLeaf(TreeNode *root) {
    return get_sum(root, 0);
  }

  int get_sum(TreeNode *node, int current_count) {
    if (!node) return 0;
    current_count = current_count << 1 | node->val;
    if (node->left == nullptr && node->right == nullptr) {
      return current_count;
    }
    return get_sum(node->left, current_count) +
           get_sum(node->right, current_count);
  }
};

void delete_tree_node(TreeNode *root) {
  if (!root) return;
  delete_tree_node(root->left);
  delete_tree_node(root->right);
  delete root;
}

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  TreeNode *input =
      new TreeNode(1, new TreeNode(0, new TreeNode(0), new TreeNode(1)),
                   new TreeNode(1, new TreeNode(0), new TreeNode(1)));
  int result = sol.sumRootToLeaf(input);
  int result_expected = 22;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;
  delete_tree_node(input);

  // Test Case 2
  cout << "Test Case 2: " << endl;
  input = new TreeNode(0);
  result = sol.sumRootToLeaf(input);
  result_expected = 0;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;
  delete_tree_node(input);
  input = nullptr;
  return 0;
}