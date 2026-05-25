//
// Created by Milo on 5/25/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
  bool canReach(string s, int minJump, int maxJump) {
    int n = s.length();
    queue<int> idx_q;
    idx_q.push(0);
    int max_dist = 0;
    while (!idx_q.empty()) {
      int idx = idx_q.front();
      idx_q.pop();
      if (idx == n - 1) return true;
      int start = max(idx + minJump, max_dist + 1);
      int end = min(idx + maxJump, n - 1);
      for (int i = start; i <= end; i++) {
        if (s[i] == '0') {
          idx_q.push(i);
        }
      }
      max_dist = max(max_dist, end);
    }
    return false;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  bool result = sol.canReach("011010", 2, 3);
  bool result_expected = true;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.canReach("01101110", 2, 3);
  result_expected = false;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}