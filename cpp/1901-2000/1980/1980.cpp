//
// Created by Milo on 3/8/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

class Solution {
 public:
  string findDifferentBinaryString(vector<string>& nums) {
    string result;
    result.reserve(nums.size());
    return search_string(result, nums);
  }
  string search_string(string current_string, vector<string>& nums) {
    if (nums.size() == current_string.length()) {
      if (find(nums.begin(), nums.end(), current_string) == nums.end()) {
        return current_string;
      }
      return "";
    }
    string result = search_string(current_string + "0", nums);
    if (result != "") {
      return result;
    }
    return search_string(current_string + "1", nums);
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<string> input = {"01", "10"};
  string result = sol.findDifferentBinaryString(input);
  string result_expected = "00";
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  input = {"00", "01"};
  result = sol.findDifferentBinaryString(input);
  result_expected = "10";
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  input = {"111", "011", "001"};
  result = sol.findDifferentBinaryString(input);
  result_expected = "000";
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}