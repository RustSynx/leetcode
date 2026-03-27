//
// Created by Milo on 3/27/26.
//
#include <algorithm>
#include <cassert>
#include <deque>
#include <iostream>

using namespace std;

class Solution {
 public:
  bool areSimilar(vector<vector<int>>& mat, int k) {
    if (k % mat[0].size() == 0) return true;
    deque<int> dq;
    for (int i = 0; i < mat.size(); i++) {
      for (int j = 0; j < k % mat[0].size(); j++) {
        if (dq.empty()) {
          dq.push_back(mat[i][mat[0].size() - 1]);
          for (int l = 0; l < mat[0].size() - 1; l++) {
            dq.push_back(mat[i][l]);
          }
        } else {
          dq.push_front(dq.back());
          dq.pop_back();
        }
      }
      for (int j = 0; j < mat[0].size(); j++) {
        if (dq.front() != mat[i][j]) return false;
        dq.pop_front();
      }
    }
    return true;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<vector<int>> input = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  bool result = sol.areSimilar(input, 4);
  bool result_expected = false;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  input = {{1, 2, 1, 2}, {5, 5, 5, 5}, {6, 3, 6, 3}};
  result = sol.areSimilar(input, 2);
  result_expected = true;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  input = {{2, 2}, {2, 2}};
  result = sol.areSimilar(input, 3);
  result_expected = true;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}