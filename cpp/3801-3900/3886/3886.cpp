//
// Created by Milo on 10/20/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int sortableIntegers(vector<int>& nums) {
    int n = nums.size();
    vector<int> k_v;
    for (int i = 1; i * i <= n; i++) {
      if (n % i == 0) {
        k_v.push_back(i);
        if (i * i != n) {
          k_v.push_back(n / i);
        }
      }
    }
    vector<int> drop_idx;
    vector<int> drop_prefix(n);
    for (int i = 0; i < n - 1; i++) {
      drop_prefix[i + 1] = drop_prefix[i];
      if (nums[i] > nums[i + 1]) {
        drop_idx.push_back(i);
        drop_prefix[i + 1]++;
      }
    }
    int total_drops = drop_idx.size();
    long long result = 0;
    for (int k : k_v) {
      int num_blocks = n / k;
      if (total_drops > num_blocks) {
        continue;
      }
      bool valid = true;
      int prev_max = -1;
      for (int i = 0; i < num_blocks; i++) {
        int L = i * k;
        int R = L + k - 1;
        int drops_in_block = drop_prefix[R] - drop_prefix[L];
        int cur_min = -1;
        int cur_max = -1;
        if (drops_in_block == 0) {
          cur_min = nums[L];
          cur_max = nums[R];
        } else if (drops_in_block == 1) {
          if (nums[R] > nums[L]) {
            valid = false;
            break;
          }
          int p = drop_idx[drop_prefix[L]];
          cur_max = nums[p];
          cur_min = nums[p + 1];
        } else {
          valid = false;
          break;
        }
        if (prev_max > cur_min) {
          valid = false;
          break;
        }
        prev_max = cur_max;
      }
      if (valid) {
        result += k;
      }
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> nums = {3, 1, 2};
  int result = sol.sortableIntegers(nums);
  int result_expected = 3;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums = {7, 6, 5};
  result = sol.sortableIntegers(nums);
  result_expected = 0;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  nums = {5, 8};
  result = sol.sortableIntegers(nums);
  result_expected = 3;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}