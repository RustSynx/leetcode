//
// Created by Milo on 2/8/26.
//

#include <algorithm>
#include <cassert>
#include <deque>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  long long countSubarrays(vector<int>& nums, long long k) {
    long long result = 0;
    int start = 0;
    deque<int> max_deque;
    deque<int> min_deque;
    for (int i = 0; i < nums.size(); i++) {
      while (!max_deque.empty() && nums[max_deque.back()] <= nums[i]) {
        max_deque.pop_back();
      }
      max_deque.push_back(i);
      while (!min_deque.empty() && nums[min_deque.back()] >= nums[i]) {
        min_deque.pop_back();
      }
      min_deque.push_back(i);
      while (start <= i && (long long)((nums[max_deque.front()] - nums[min_deque.front()])) * (i - start + 1) > k) {
        start++;
        if (!max_deque.empty() && max_deque.front() < start) {
          max_deque.pop_front();
        }
        if (!min_deque.empty() && min_deque.front() < start) {
          min_deque.pop_front();
        }
      }
      result += i - start + 1;
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> nums = {1, 3, 2};
  long long result = sol.countSubarrays(nums, 4);
  long long result_expected = 5;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  nums = {5, 5, 5, 5};
  result = sol.countSubarrays(nums, 0);
  result_expected = 10;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  nums = {1, 2, 3};
  result = sol.countSubarrays(nums, 0);
  result_expected = 3;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}