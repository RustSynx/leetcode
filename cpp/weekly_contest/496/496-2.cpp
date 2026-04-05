//
// Created by Milo on 4/5/26.
//
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> findGoodIntegers(int n) {
    int x = 0;
    vector<int> result;
    unordered_map<int, int> pairs;
    for (int a = 1; a * a * a <= n; a++) {
      for (int b = a; b < 1000; b++) {
        x = a * a * a + b * b * b;
        if (x > n) break;
        pairs[x]++;
        if (pairs[x] == 2) result.push_back(x);
      }
    }
    sort(result.begin(), result.end());
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> result = sol.findGoodIntegers(4104);
  vector<int> result_expected = {1729, 4104};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.findGoodIntegers(578);
  result_expected = {};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}