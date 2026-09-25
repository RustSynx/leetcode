//
// Created by Milo on 9/25/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<string> braceExpansionII(string expression) {
    set<string> str_set;
    dfs(str_set, expression);
    vector<string> result(str_set.begin(), str_set.end());
    return result;
  }
  void dfs(set<string>& str_set, string s) {
    int right = s.find('}');
    if (right == string::npos) {
      str_set.insert(s);
      return;
    }
    int left = s.rfind('{', right);
    string sub = s.substr(left + 1, right - left - 1);
    vector<string> s_v;
    int pos;
    while ((pos = sub.find(',')) != string::npos) {
      s_v.push_back(sub.substr(0, pos));
      sub.erase(0, pos + 1);
    }
    s_v.push_back(sub);
    for (string ss : s_v) {
      string new_s = s.substr(0, left) + ss + s.substr(right + 1);
      dfs(str_set, new_s);
    }
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<string> result = sol.braceExpansionII("{a,b}{c,{d,e}}");
  vector<string> result_expected = {"ac", "ad", "ae", "bc", "bd", "be"};
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.braceExpansionII("{{a,z},a{b,c},{ab,z}}");
  result_expected = {"a", "ab", "ac", "z"};
  assert(result == result_expected);
  cout << "PASSED" << endl;
  return 0;
}