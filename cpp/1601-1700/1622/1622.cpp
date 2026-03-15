//
// Created by Milo on 3/15/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

class Fancy {
 public:
  long long mod = 1e9 + 7;
  vector<long long> seq;
  long long acc_sum = 0;
  long long acc_mul = 1;

  Fancy() {}

  void append(int val) {
    long long x = (val - acc_sum % mod + mod) % mod;
    x = x * power(acc_mul, mod - 2) % mod;
    seq.push_back(x);
  }

  void addAll(int inc) { acc_sum = (acc_sum + inc) % mod; }

  void multAll(int m) {
    acc_sum = m * acc_sum % mod;
    acc_mul = m * acc_mul % mod;
  }

  int getIndex(int idx) {
    if (seq.size() <= idx) return -1;
    return static_cast<int>((seq[idx] * acc_mul % mod + acc_sum) % mod);
  }

  long long power(long long base, long long exp) {
    long long res = 1;
    base %= mod;
    while (exp > 0) {
      if (exp % 2 == 1) res = (res * base) % mod;
      base = (base * base) % mod;
      exp /= 2;
    }
    return res;
  }
};

int main() {
  Fancy fan;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  int result = sol.minPartitions("32");
  int result_expected = 3;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.minPartitions("82734");
  result_expected = 8;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  result = sol.minPartitions("27346209830709182346");
  result_expected = 9;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}