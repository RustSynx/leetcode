//
// Created by Milo on 8/19/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
#include <array>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
    unordered_map<int, array<int, 11>> map;
    for (vector<int>& v : reservedSeats) {
      map[v[0]][v[1]] = 1;
    }
    int result = (n - map.size()) * 2;
    for (auto& [row, seats] : map) {
      int left_seat = seats[2] + seats[3] + seats[4] + seats[5];
      int middle_seat = seats[4] + seats[5] + seats[6] + seats[7];
      int right_seat = seats[6] + seats[7] + seats[8] + seats[9];
      if (left_seat == 0 && right_seat == 0) {
        result += 2;
      } else if (left_seat == 0 || middle_seat == 0 || right_seat == 0) {
        result += 1;
      }
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<vector<int>> reservedSeats = {{1, 2}, {1, 3}, {1, 8},
                                       {2, 6}, {3, 1}, {3, 10}};
  int result = sol.maxNumberOfFamilies(3, reservedSeats);
  int result_expected = 4;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  reservedSeats = {{2, 1}, {1, 8}, {2, 6}};
  result = sol.maxNumberOfFamilies(2, reservedSeats);
  result_expected = 2;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  reservedSeats = {{4, 3}, {1, 4}, {4, 6}, {1, 7}};
  result = sol.maxNumberOfFamilies(4, reservedSeats);
  result_expected = 4;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}