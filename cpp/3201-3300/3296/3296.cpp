//
// Created by Milo on 3/13/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool canReduce(long long limit_time, int target_height, const vector<int>& workerTimes) {
    long long total_reduced = 0;

    for (long long t : workerTimes) {
      long long left = 0;
      long long right = 200000;
      long long max_k = 0;

      while (left <= right) {
        long long k = left + (right - left) / 2;
        long long time_needed = t * k * (k + 1) / 2;

        if (time_needed <= limit_time) {
          max_k = k;
          left = k + 1;
        } else {
          right = k - 1;
        }
      }

      total_reduced += max_k;
      if (total_reduced >= target_height) return true;
    }

    return total_reduced >= target_height;
  }

  long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
    long long left = 0;
    long long max_time = *max_element(workerTimes.begin(), workerTimes.end());
    long long h = mountainHeight;
    long long right = max_time * h * (h + 1) / 2;
    long long answer = right;

    while (left <= right) {
      long long mid = left + (right - left) / 2;

      if (canReduce(mid, mountainHeight, workerTimes)) {
        answer = mid;
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }

    return answer;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> input = {2, 1, 1};
  int result = sol.minNumberOfSeconds(4, input);
  int result_expected = 3;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  input = {3, 2, 2, 4};
  result = sol.minNumberOfSeconds(10, input);
  result_expected = 12;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  input = {1};
  result = sol.minNumberOfSeconds(5, input);
  result_expected = 15;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}