//
// Created by Milo on 2/20/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

class Solution {
 public:
  string makeLargestSpecial(string s) {
    vector<string> special_string_vector;
    special_string_vector.reserve(s.size());
    int count = 0;
    int left = 0;
    for (int i = 0; i < s.size(); i++) {
      s[i] == '1' ? count++ : count--;
      if (count == 0) {
        string sorted_string = makeLargestSpecial(s.substr(left + 1, i - left - 1));
        special_string_vector.push_back('1' + sorted_string + '0');
        left = i + 1;
      }
    }
    sort(special_string_vector.begin(), special_string_vector.end(), greater<string>());

    string result = "";
    for (string s : special_string_vector) {
      result += s;
    }

    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  string result = sol.makeLargestSpecial("11011000");
  string result_expected = "11100100";
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.makeLargestSpecial("10");
  result_expected = "10";
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}