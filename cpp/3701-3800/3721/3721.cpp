//
// Created by Milo on 2/10/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct Node {
    int min_value;
    int max_value;
    int balanced_value;
};

class Tree {
public:
    vector<Node> tree;

    Tree(int array_size) : tree(4 * array_size, {0, 0, 0}){}

    void push(int node) {
        if (tree[node].balanced_value != 0) {
            tree[node * 2].balanced_value += tree[node].balanced_value;
            tree[node * 2].min_value += tree[node].balanced_value;
            tree[node * 2].max_value += tree[node].balanced_value;

            tree[node * 2 + 1].balanced_value += tree[node].balanced_value;
            tree[node * 2 + 1].min_value += tree[node].balanced_value;
            tree[node * 2 + 1].max_value += tree[node].balanced_value;

            tree[node].balanced_value = 0;
        }
    }

    void update(int node, int start, int end, int left, int right, int balanced_check_value) {
        if (right < start || end < left) return;

        if (left <= start && end <= right) {
            tree[node].balanced_value += balanced_check_value;
            tree[node].min_value += balanced_check_value;
            tree[node].max_value += balanced_check_value;
            return;
        }

        push(node);

        int mid = (start + end) / 2;
        update(node * 2, start, mid, left, right, balanced_check_value);
        update(node * 2 + 1, mid + 1, end, left, right, balanced_check_value);

        tree[node].min_value = min(tree[node * 2].min_value, tree[node * 2 + 1].min_value);
        tree[node].max_value = max(tree[node * 2].max_value, tree[node * 2 + 1].max_value);
    }

    int findFirstZero(int node, int start, int end) {
        if (tree[node].min_value > 0 || tree[node].max_value < 0) return -1;

        if (start == end) {
            return (tree[node].min_value == 0) ? start : -1;
        }

        push(node);

        int mid = (start + end) / 2;

        int res = findFirstZero(node * 2, start, mid);

        if (res == -1) {
            res = findFirstZero(node * 2 + 1, mid + 1, end);
        }
        return res;
    }
};

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int array_length = nums.size();
        Tree tree(array_length);
        unordered_map<int, int> last_pos;
        int max_length = 0;

        for (int i = 0; i < array_length; i++) {
            int num = nums[i];
            int balanced_check_value = (num % 2 != 0) ? 1 : -1;

            int prev = 0;
            if (last_pos.count(num)) {
                prev = last_pos[num] + 1;
            }

            tree.update(1, 0, array_length - 1, prev, i, balanced_check_value);

            int first_zero_idx = tree.findFirstZero(1, 0, array_length - 1);

            if (first_zero_idx != -1 && first_zero_idx <= i) {
              max_length = max(max_length, i - first_zero_idx + 1);
            }
            last_pos[num] = i;
        }
        return max_length;
    }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector nums = {2, 5, 4, 3};
  int result = sol.longestBalanced(nums);
  int result_expected = 4;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums = {3, 2, 2, 5, 4};
  result = sol.longestBalanced(nums);
  result_expected = 5;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  nums = {1, 2, 3, 2};
  result = sol.longestBalanced(nums);
  result_expected = 3;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}