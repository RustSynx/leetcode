//
// Created by Milo on 2/2/26.
//
#include <cassert>
#include <deque>
#include <iostream>
#include <vector>

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
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    deque<int> dq_l1;
    deque<int> dq_l2;
    while (l1 != nullptr || l2 != nullptr) {
      if (l1 == nullptr) {
        dq_l1.push_back(0);
      } else {
        dq_l1.push_back(l1->val);
        l1 = l1->next;
      }
      if (l2 == nullptr) {
        dq_l2.push_back(0);
      } else {
        dq_l2.push_back(l2->val);
        l2 = l2->next;
      }
    }
    bool shouldIncrease = false;
    int sum;
    ListNode* result = new ListNode();
    ListNode* curr = result;
    for (int i = 0; i < dq_l1.size(); i++) {
      sum = dq_l1[i] + dq_l2[i] + (shouldIncrease ? 1 : 0);
      if (sum > 9) {
        sum %= 10;
        shouldIncrease = true;
      } else {
        shouldIncrease = false;
      }
      curr->val = sum;
      if (dq_l1.size() - 1 != i) {
        curr->next = new ListNode();
        curr = curr->next;
      }
      if (dq_l1.size() - 1 == i && shouldIncrease) {
        curr->next = new ListNode();
        curr = curr->next;
        curr->val = 1;
      }
    }
    return result;
  }
};

ListNode* createList(const vector<int>& values) {
  if (values.empty()) return nullptr;
  ListNode* head = new ListNode(values[0]);
  ListNode* curr = head;
  for (int i = 1; i < values.size(); i++) {
    curr->next = new ListNode(values[i]);
    curr = curr->next;
  }
  return head;
}

void deleteList(ListNode* head) {
  while (head != nullptr) {
    ListNode* temp = head;
    head = head->next;
    delete temp;
  }
}

vector<int> listToVector(ListNode* head) {
  vector<int> result;
  while (head != nullptr) {
    result.push_back(head->val);
    head = head->next;
  }
  return result;
}

int main() {
  Solution sol;

  // Test Case 1
  ListNode* l1 = createList({2, 4, 3});
  ListNode* l2 = createList({5, 6, 4});
  ListNode* result = sol.addTwoNumbers(l1, l2);

  cout << "Test Case 1: ";
  vector<int> result_expected = {7, 0, 8};
  vector<int> result_vec = listToVector(result);
  assert(result_vec == result_expected);
  cout << " PASSED" << endl;

  // Clean up memory
  deleteList(l1);
  deleteList(l2);
  deleteList(result);

  // Test Case 2
  cout << "Test Case 2: ";
  l1 = createList({0});
  l2 = createList({0});
  result = sol.addTwoNumbers(l1, l2);
  result_expected = {0};
  result_vec = listToVector(result);
  assert(result_vec == result_expected);
  cout << " PASSED" << endl;

  // Clean up memory
  deleteList(l1);
  deleteList(l2);
  deleteList(result);

  // Test Case 3
  cout << "Test Case 3: ";
  l1 = createList({9, 9, 9, 9, 9, 9, 9});
  l2 = createList({9, 9, 9, 9});
  result = sol.addTwoNumbers(l1, l2);
  result_expected = {8, 9, 9, 9, 0, 0, 0, 1};
  result_vec = listToVector(result);
  assert(result_vec == result_expected);
  cout << " PASSED" << endl;

  // Clean up memory
  deleteList(l1);
  deleteList(l2);
  deleteList(result);

  return 0;
}