//
// Created by Milo on 4/11/26.
//
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int minOperations(vector<int>& nums) {
    int prime_range = 100004;
    vector<bool> check_prime(prime_range, true);
    check_prime[0] = check_prime[1] = false;

    for (int i = 2; i * i < prime_range; i++) {
      if (check_prime[i]) {
        for (int j = i * i; j < prime_range; j += i) {
          check_prime[j] = false;
        }
      }
    }

    int n = static_cast<int>(nums.size());
    int result = 0;
    for (int i = 0; i < n; i++) {
      if ((i & 1) == 0) {
        if (nums[i] == 1) {
          result++;
          continue;
        }
        while (!check_prime[nums[i]]) {
          nums[i]++;
          result++;
        }
      } else {
        if (!check_prime[nums[i]]) {
          continue;
        }
        if (nums[i] == 2) {
          result += 2;
        } else if ((nums[i] & 1) != 0) {
          result += 1;
        }
      }
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> nums = {1, 2, 3, 4};
  int result = sol.minOperations(nums);
  int result_expected = 3;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums = {5, 6, 7, 8};
  result = sol.minOperations(nums);
  result_expected = 0;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  nums = {1, 9, 8};
  result = sol.minOperations(nums);
  result_expected = 4;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}