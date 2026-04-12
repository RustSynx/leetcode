//
// Created by Milo on 4/12/26.
//
#include <cassert>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
  int longestBalanced(string s) {
    int n = static_cast<int>(s.length());
    int zeros_count = 0;
    int ones_count = 0;
    int zeros_distance = 0;
    int ones_distance = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '0') {
        zeros_count++;
      } else {
        ones_count++;
      }
    }
    int result = 0;
    int current_sum = 0;
    unordered_map<int, int> prefix_sum_map;
    unordered_map<int, int> first_idx_zero;
    unordered_map<int, int> first_idx_one;
    prefix_sum_map[0] = -1;
    for (int i = 0; i < n; i++) {
      int add_num = s[i] == '0' ? -1 : 1;
      current_sum += add_num;
      if (s[i] == '0') zeros_distance++;
      else ones_distance++;
      if (prefix_sum_map.contains(current_sum)) {
        result = max(result, i - prefix_sum_map[current_sum]);
      }
      if (prefix_sum_map.contains(current_sum - 2)) {
        int len = i - prefix_sum_map[current_sum - 2];
        int internal_zeros = (len - 2) / 2;

        if (zeros_count > internal_zeros) {
          result = max(result, len);
        } else if (first_idx_zero.contains(current_sum - 2)) {
          result = max(result, i - first_idx_zero[current_sum - 2]);
        }
      }
      if (prefix_sum_map.contains(current_sum + 2)) {
        int len = i - prefix_sum_map[current_sum + 2];
        int internal_ones = (len - 2) / 2;

        if (ones_count > internal_ones) {
          result = max(result, len);
        }else if (first_idx_one.contains(current_sum + 2)) {
          result = max(result, i - first_idx_one[current_sum + 2]);
        }
      }
      if (!prefix_sum_map.contains(current_sum)) {
        prefix_sum_map[current_sum] = i;
      }
      if (zeros_distance > 0 && !first_idx_zero.contains(current_sum)) {
        first_idx_zero[current_sum] = i;
      }
      if (ones_distance > 0 && !first_idx_one.contains(current_sum)) {
        first_idx_one[current_sum] = i;
      }
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  int result = sol.longestBalanced("100001");
  int result_expected = 4;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.longestBalanced("00001");
  result_expected = 2;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}