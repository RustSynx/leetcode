//
// Created by Milo on 10/10/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1,
                             int k2) {
    int n = nums1.size();
    long long K = k1 + k2;
    vector<int> diff(1e5 + 1);
    for (int i = 0; i < n; i++) {
      diff[abs(nums1[i] - nums2[i])]++;
    }
    long long result = 0;
    for (int i = 1e5; i > 0; i--) {
      if (diff[i] == 0) continue;
      if (K > 0) {
        if (K >= diff[i]) {
          K -= diff[i];
          diff[i - 1] += diff[i];
        } else {
          diff[i] -= K;
          result += static_cast<long long>(i) * i * diff[i];
          diff[i - 1] += K;
          K = 0;
        }
      } else {
        result += static_cast<long long>(i) * i * diff[i];
      }
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<int> num1 = {1, 2, 3, 4};
  vector<int> num2 = {2, 10, 20, 19};
  int result = sol.minSumSquareDiff(num1, num2, 0, 0);
  int result_expected = 579;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  num1 = {1, 4, 10, 12};
  num2 = {5, 8, 6, 9};
  result = sol.minSumSquareDiff(num1, num2, 1, 1);
  result_expected = 43;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}