//
// Created by Milo on 6/7/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

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
  TreeNode *createBinaryTree(vector<vector<int>> &descriptions) {
    unordered_map<int, vector<int>> parent_map;
    unordered_set<int> left_right_set;
    for (vector<int> &description : descriptions) {
      if (!parent_map.contains(description[0])) {
        parent_map.emplace(description[0], vector<int>(2, 0));
      }
      if (description[2] == 1) {
        parent_map[description[0]][0] = description[1];
      } else {
        parent_map[description[0]][1] = description[1];
      }
      left_right_set.insert(description[1]);
    }
    int parent_value = 0;
    for (auto &[key, value] : parent_map) {
      if (!left_right_set.contains(key)) {
        parent_value = key;
        break;
      }
    }
    TreeNode *result = new TreeNode(parent_value);
    queue<TreeNode *> q;
    q.push(result);
    while (!q.empty()) {
      TreeNode *parent = q.front();
      q.pop();
      if (parent == nullptr) continue;
      if (parent_map.contains(parent->val)) {
        vector<int> val = parent_map[parent->val];
        parent->left = val[0] == 0 ? nullptr : new TreeNode(val[0]);
        parent->right = val[1] == 0 ? nullptr : new TreeNode(val[1]);
        q.push(parent->left);
        q.push(parent->right);
      }
    }
    return result;
  }
};

void delete_tree_node(TreeNode *root) {
  if (!root) return;
  delete_tree_node(root->left);
  delete_tree_node(root->right);
  delete root;
}

bool isSameTree(TreeNode* t1, TreeNode* t2) {
  if (t1 == nullptr && t2 == nullptr) return true;
  if (t1 == nullptr || t2 == nullptr) return false;
  if (t1->val != t2->val) return false;
  return isSameTree(t1->left, t2->left) && isSameTree(t1->right, t2->right);
}

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<vector<int>> descriptions = {
      {20, 15, 1}, {20, 17, 0}, {50, 20, 1}, {50, 80, 0}, {80, 19, 1}};
  TreeNode *result = sol.createBinaryTree(descriptions);
  TreeNode *result_expected =
      new TreeNode(50, new TreeNode(20, new TreeNode(15), new TreeNode(17)),
                   new TreeNode(80, new TreeNode(19), nullptr));
  assert(isSameTree(result, result_expected));
  cout << "PASSED" << endl;
  delete_tree_node(result);
  delete_tree_node(result_expected);

  // Test Case 2
  cout << "Test Case 2: " << endl;
  descriptions = {{1, 2, 1}, {2, 3, 0}, {3, 4, 1}};
  result = sol.createBinaryTree(descriptions);
  result_expected = new TreeNode(
      1, new TreeNode(2, nullptr, new TreeNode(3, new TreeNode(4), nullptr)),
      nullptr);
  assert(isSameTree(result, result_expected));
  cout << "PASSED" << endl;
  delete_tree_node(result);
  delete_tree_node(result_expected);

  return 0;
}