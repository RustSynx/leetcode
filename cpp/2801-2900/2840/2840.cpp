//
// Created by Milo on 3/30/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>

using namespace std;

class Solution {
 public:
  bool checkStrings(string s1, string s2) {
    multiset<char> s1_even_set;
    multiset<char> s2_even_set;
    multiset<char> s1_odd_set;
    multiset<char> s2_odd_set;
    for (int i = 0; i < s1.length(); i++) {
      if (i % 2 == 0) {
        s1_even_set.insert(s1[i]);
        s2_even_set.insert(s2[i]);
      } else {
        s1_odd_set.insert(s1[i]);
        s2_odd_set.insert(s2[i]);
      }
    }
    return s1_even_set == s2_even_set && s1_odd_set == s2_odd_set;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  bool result = sol.checkStrings("abcdba", "cabdab");
  bool result_expected = true;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.checkStrings("abe", "bea");
  result_expected = false;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}