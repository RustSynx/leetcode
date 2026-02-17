//
// Created by Milo on 2/17/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

class Solution {
public:
  vector<string> readBinaryWatch(int turnedOn) {
    vector<string> result;
    for (int i = 0; i < 12; i++) {
      for (int j = 0; j < 60; j++) {
        int hour_count = bits_count(i);
        int minute_count = bits_count(j);
        if (hour_count + minute_count == turnedOn) {
          string minute = to_string(j);
          minute = j < 10 ? "0" + minute : minute;
          result.push_back(to_string(i) + ":" + minute);
        }
      }
    }
    return result;
  }
  int bits_count(int num) {
    int count = 0;
    while (num > 0) {
      if (num % 2 == 1) count++;
      num /= 2;
    }
    return count;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<string> result = sol.readBinaryWatch(1);
  vector<string> result_expected = {"0:01","0:02","0:04","0:08","0:16","0:32","1:00","2:00","4:00","8:00"};
  cout << "result : ";
  for (string s : result) {
    cout << s << " ";
  }
  cout << endl;
  cout << "result : ";
  for (string s : result_expected) {
    cout << s << " ";
  }
  cout << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.readBinaryWatch(9);
  result_expected = {};
  cout << "result : ";
  for (string s : result) {
    cout << s << " ";
  }
  cout << endl;
  cout << "result : ";
  for (string s : result_expected) {
    cout << s << " ";
  }
  cout << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}