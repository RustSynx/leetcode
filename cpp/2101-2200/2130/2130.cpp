//
// Created by Milo on 6/14/26.
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

void deleteList(ListNode* head) {
  while (head != nullptr) {
    ListNode* temp = head;
    head = head->next;
    delete temp;
  }
}

class Solution {
 public:
  int pairSum(ListNode *head) {
    vector<int> vector_node;
    vector_node.reserve(1e5);
    ListNode* next_head = head;
    while (next_head != nullptr) {
      vector_node.push_back(next_head->val);
      next_head = next_head->next;
    }
    int n = static_cast<int>(vector_node.size());
    int start = 0;
    int end = (n / 2) - 1;
    int result = 0;
    while (start <= end) {
      int twin_idx = n - 1 - start;
      result = max(result, vector_node[start] + vector_node[twin_idx]);
      start++;
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  ListNode* head = new ListNode(5, new ListNode(4, new ListNode(2, new ListNode(1))));
  int result = sol.pairSum(head);
  int result_expected = 6;
  assert(result == result_expected);
  deleteList(head);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  head = new ListNode(4, new ListNode(2, new ListNode(2, new ListNode(3))));
  result = sol.pairSum(head);
  result_expected = 7;
  assert(result == result_expected);
  deleteList(head);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  head = new ListNode(1, new ListNode(100000));
  result = sol.pairSum(head);
  result_expected = 100001;
  assert(result == result_expected);
  deleteList(head);
  cout << "PASSED" << endl;

  return 0;
}