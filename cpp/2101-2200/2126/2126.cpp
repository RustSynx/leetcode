//
// Created by Milo on 5/31/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
    int n = static_cast<int>(asteroids.size());
    ranges::sort(asteroids);
    long long sum = mass;
    for (int i = 0; i < n; i++) {
      int a_mass = asteroids[i];
      if (sum >= a_mass) {
        sum += a_mass;
      } else {
        return false;
      }
    }
    return true;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> asteroids = {3, 9, 19, 5, 21};
  bool result = sol.asteroidsDestroyed(10, asteroids);
  bool result_expected = true;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  asteroids = {4, 9, 23, 4};
  result = sol.asteroidsDestroyed(5, asteroids);
  result_expected = false;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}