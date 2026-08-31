//
// Created by Milo on 8/31/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
 public:
  vector<int> nodesBetweenCriticalPoints(ListNode *head) {
    int max_val = INT_MIN;
    int min_val = INT_MAX;
    int first_dst = -1;
    int prev_dst = -1;
    int curr_dst = 0;
    int prev = head->val;
    head = head->next;
    while (head->next != nullptr) {
      curr_dst++;
      int curr = head->val;
      int next_val = head->next->val;
      if ((prev < curr && next_val < curr) || (prev > curr && next_val > curr)) {
        if (first_dst == -1) {
          first_dst = curr_dst;
        } else {
          max_val = max(max_val, curr_dst - first_dst);
        }
        if (prev_dst != -1) {
          min_val = min(min_val, curr_dst - prev_dst);
        }
        prev_dst = curr_dst;
      }
      prev = curr;
      head = head->next;
    }
    if (max_val == INT_MIN) return {-1, -1};
    return {min_val, max_val};
  }
};

void deleteListNode(ListNode* root) {
  if (!root) return;
  deleteListNode(root->next);
  delete root;
}

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  ListNode *head = new ListNode(3, new ListNode(1));
  vector<int> result = sol.nodesBetweenCriticalPoints(head);
  vector<int> result_expected = {-1, -1};
  assert(result == result_expected);
  deleteListNode(head);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  head = new ListNode(
      5,
      new ListNode(
          3,
          new ListNode(
              1, new ListNode(
                     2, new ListNode(5, new ListNode(1, new ListNode(2)))))));
  result = sol.nodesBetweenCriticalPoints(head);
  result_expected = {1, 3};
  assert(result == result_expected);
  deleteListNode(head);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  head = new ListNode(
      1,
      new ListNode(
          3, new ListNode(
                 2, new ListNode(
                        2, new ListNode(
                               3, new ListNode(
                                      2, new ListNode(
                                             2, new ListNode(
                                                    2, new ListNode(7)))))))));
  result = sol.nodesBetweenCriticalPoints(head);
  result_expected = {3, 3};
  assert(result == result_expected);
  deleteListNode(head);
  cout << "PASSED" << endl;

  return 0;
}