//
// Created by Milo on 9/30/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
  vector<int> maxDepthAfterSplit(string seq) {
    int n = seq.length();
    int depth = 0;
    vector<int> result(n);
    for (int i = 0; i < n; i++) {
      if (seq[i] == '(') {
        depth++;
        result[i] = depth % 2;
      } else {
        result[i] = depth % 2;
        depth--;
      }
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> result = sol.maxDepthAfterSplit("(()())");
  vector<int> result_expected = {0,1,1,1,1,0};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.maxDepthAfterSplit("()(())()");
  result_expected = {0,0,0,1,1,0,1,1};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}