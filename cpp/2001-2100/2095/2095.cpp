//
// Created by Milo on 6/15/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

void deleteListNode(ListNode* root) {
  if (!root) return;
  deleteListNode(root->next);
  delete root;
}

bool isSameList(ListNode* l1, ListNode* l2) {
  while (l1 != nullptr && l2 != nullptr) {
    if (l1->val != l2->val) return false;
    l1 = l1->next;
    l2 = l2->next;
  }
  return l1 == nullptr && l2 == nullptr;
}

class Solution {
 public:
  ListNode* deleteMiddle(ListNode* head) {
    if (head->next == nullptr) {
      delete head;
      return nullptr;
    }
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev_mid = head;
    while (fast != nullptr && fast->next != nullptr) {
      prev_mid = slow;
      slow = slow->next;
      fast = fast->next->next;
    }
    prev_mid->next = slow->next;
    delete slow;
    return head;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  ListNode* head = new ListNode(
      1,
      new ListNode(
          3,
          new ListNode(
              4, new ListNode(
                     7, new ListNode(1, new ListNode(2, new ListNode(6)))))));
  ListNode* result = sol.deleteMiddle(head);
  ListNode* result_expected = new ListNode(
      1, new ListNode(
             3, new ListNode(
                    4, new ListNode(1, new ListNode(2, new ListNode(6))))));
  assert(isSameList(result, result_expected));
  deleteListNode(result);
  deleteListNode(result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));
  result = sol.deleteMiddle(head);
  result_expected = new ListNode(1, new ListNode(2, new ListNode(4)));
  assert(isSameList(result, result_expected));
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  head = new ListNode(2, new ListNode(1));
  result = sol.deleteMiddle(head);
  result_expected = new ListNode(2);
  assert(isSameList(result, result_expected));
  cout << "PASSED" << endl;

  return 0;
}