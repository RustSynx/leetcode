//
// Created by Milo on 5/20/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
    int n = static_cast<int>(A.size());
    int count = 0;
    vector<int> common_check(n + 1, 0);
    vector<int> result(n);
    for (int i = 0; i < n; i++) {
      common_check[A[i]]++;
      if (common_check[A[i]] == 2) count++;
      common_check[B[i]]++;
      if (common_check[B[i]] == 2) count++;
      result[i] = count;
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> A = {1, 3, 2, 4};
  vector<int> B = {3, 1, 2, 4};
  vector<int> result = sol.findThePrefixCommonArray(A, B);
  vector<int> result_expected = {0, 2, 3, 4};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  A = {2, 3, 1};
  B = {3, 1, 2};
  result = sol.findThePrefixCommonArray(A, B);
  result_expected = {0, 1, 3};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}