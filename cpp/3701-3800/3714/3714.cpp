//
// Created by Milo on 2/13/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct pair_hash {
  inline size_t operator()(const pair<int, int> &v) const {
    return v.first * 31 + v.second;
  }
};

class Solution {
 public:
  int longestBalanced(string s) {
    int result = 0;
    int input_length = s.length();
    unordered_map<pair<int, int>, int, pair_hash> three_difference_map = {
        {{0, 0}, -1}};
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < input_length; i++) {
      if (s[i] == 'a') {
        a++;
      } else if (s[i] == 'b') {
        b++;
      } else if (s[i] == 'c') {
        c++;
      }
      pair difference = {a - b, a - c};
      if (three_difference_map.count(difference)) {
        result = max(result, i - three_difference_map[difference]);
      } else {
        three_difference_map[difference] = i;
      }
    }
    vector<int> two_difference_vec(2 * input_length + 1, -2);
    vector<int> pos(2 * input_length + 1, 0);
    vector<int> visited_v(2 * input_length + 1, -1);
    int v = 0;
    int offset = input_length;
    int diff = 0;
    pos[0 + offset] = -1;
    visited_v[0 + offset] = v;
    for (int i = 0; i < input_length; i++) {
      if (s[i] == 'c') {
        v++;
        diff = 0;
        pos[0 + offset] = i;
        visited_v[0 + offset] = v;
        continue;
      }
      if (s[i] == 'a') {
        diff++;
      } else {
        diff--;
      }
      int idx = diff + offset;
      if (visited_v[idx] == v) {
        result = max(result, i - pos[idx]);
      } else {
        pos[idx] = i;
        visited_v[idx] = v; // 현재 버전 도장 쾅
      }
    }
    v++;
    diff = 0;

    pos[0 + offset] = -1;
    visited_v[0 + offset] = v;
    for (int i = 0; i < input_length; i++) {
      if (s[i] == 'b') {
        v++;
        diff = 0;
        pos[0 + offset] = i;
        visited_v[0 + offset] = v;
        continue;
      }
      if (s[i] == 'a') {
        diff++;
      } else {
        diff--;
      }
      int idx = diff + offset;
      if (visited_v[idx] == v) {
        result = max(result, i - pos[idx]);
      } else {
        pos[idx] = i;
        visited_v[idx] = v;
      }
    }
    v++;
    diff = 0;

    pos[0 + offset] = -1;
    visited_v[0 + offset] = v;
    for (int i = 0; i < input_length; i++) {
      if (s[i] == 'a') {
        v++;
        diff = 0;
        pos[0 + offset] = i;
        visited_v[0 + offset] = v;
        continue;
      }
      if (s[i] == 'b') {
        diff++;
      } else {
        diff--;
      }
      int idx = diff + offset;
      if (visited_v[idx] == v) {
        result = max(result, i - pos[idx]);
      } else {
        pos[idx] = i;
        visited_v[idx] = v;
      }
    }
    int cnt = 0;
    for (int i = 0; i < input_length; i++) {
      if (s[i] == 'a')
        result = max(result, ++cnt);
      else
        cnt = 0;
    }
    cnt = 0;
    for (int i = 0; i < input_length; i++) {
      if (s[i] == 'b')
        result = max(result, ++cnt);
      else
        cnt = 0;
    }
    cnt = 0;
    for (int i = 0; i < input_length; i++) {
      if (s[i] == 'c')
        result = max(result, ++cnt);
      else
        cnt = 0;
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  int result = sol.longestBalanced("abbac");
  int result_expected = 4;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.longestBalanced("aabcc");
  result_expected = 3;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  result = sol.longestBalanced("aba");
  result_expected = 2;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}