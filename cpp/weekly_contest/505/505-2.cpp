//
// Created by Milo on 6/7/26.
//
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<string> generateValidStrings(int n, int k) {
    vector<string> result;
    string init_str = "";
    makeString(result, 0, init_str, n, k);
    return result;
  }
  void makeString(vector<string>& result, int idx, string& curr, int n, int k) {
    if (idx == n) {
      result.push_back(curr);
      return;
    }
    if (k - idx >= 0) {
      if (idx == 0 || curr.back() != '1') {
        curr.append("1");
        makeString(result, idx + 1, curr, n, k - idx);
        curr.pop_back();
      }
    }
    curr.append("0");
    makeString(result, idx + 1, curr, n, k);
    curr.pop_back();
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<string> result = sol.generateValidStrings(3, 1);
  vector<string> result_expected = {"000", "010", "100"};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.generateValidStrings(1, 0);
  result_expected = {"0", "1"};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}