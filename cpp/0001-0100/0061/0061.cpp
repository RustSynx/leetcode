//
// Created by Milo on 5/5/26.
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

class Solution {
 public:
  ListNode* rotateRight(ListNode* head, int k) {
    if (head == nullptr || k == 0) return head;
    ListNode* next = head;
    int size = 0;
    ListNode* last = nullptr;
    while (next != nullptr) {
      size++;
      if (next->next == nullptr) last = next;
      next = next->next;
    }
    k %= size;
    if (k == 0) return head;
    ListNode* current_node = head;
    for (int i = 0; i < size - k - 1; i++) {
      current_node = current_node->next;
    }
    last->next = head;
    head = current_node->next;
    current_node->next = nullptr;
    return head;
  }
};

ListNode* createList(const vector<int>& arr) {
  if (arr.empty()) return nullptr;
  ListNode* head = new ListNode(arr[0]);
  ListNode* current = head;
  for (int i = 1; i < arr.size(); i++) {
    current->next = new ListNode(arr[i]);
    current = current->next;
  }
  return head;
}

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

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  ListNode* head = createList({1, 2, 3, 4, 5});
  ListNode* result = sol.rotateRight(head, 2);
  ListNode* result_expected = createList({4, 5, 1, 2, 3});
  assert(isSameList(result, result_expected));
  cout << "PASSED" << endl;

  deleteListNode(head);
  deleteListNode(result_expected);

  // Test Case 2
  cout << "Test Case 2: " << endl;
  head = createList({0, 1, 2});
  result = sol.rotateRight(head, 4);
  result_expected = createList({2, 0, 1});
  assert(isSameList(result, result_expected));
  cout << "PASSED" << endl;

  deleteListNode(head);
  deleteListNode(result);
  deleteListNode(result_expected);

  return 0;
}