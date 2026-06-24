//
// Created by Milo on 6/24/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<long long>> Matrix;

class Solution {
public:
    int mod = 1e9 + 7;
    int zigZagArrays(int n, int l, int r) {
      int max_num = r - l + 1;
      int state_count = max_num * 2;
      Matrix state_vec(state_count, vector<long long>(state_count));
      for (int i = 0; i < state_count; i++) {
        for (int j = 0; j < state_count; j++) {
          int val_i = (i < max_num) ? i : i - max_num;
          int val_j = (j < max_num) ? j : j - max_num;

          if (i < max_num && j >= max_num) {
            if (val_i > val_j) {
              state_vec[i][j] = 1;
            }
          }

          else if (i >= max_num && j < max_num) {
            if (val_i < val_j) {
              state_vec[i][j] = 1;
            }
          }
        }
      }
      vector<long long> init_vec(state_count);
      for (int i = l; i <= r; i++) {
        for (int j = l; j <= r; j++) {
          int up_idx = j - l;

          if (i < j) {
            init_vec[up_idx]++;
          }

          if (i > j) {
            init_vec[up_idx + max_num]++;
          }
        }
      }

      Matrix square_vec(state_count, vector<long long>(state_count));

      for (int i = 0; i < state_count; i++) square_vec[i][i] = 1;
      n -= 2;
      while (n > 0) {
        if (n % 2 == 1) {
          square_vec = multiply(square_vec, state_vec);
        }
        state_vec = multiply(state_vec, state_vec);
        n /= 2;
      }

      vector<long long> final_multiply(state_count);
      int result = 0;
      for (int i = 0; i < state_count; i++) {
        for (int j = 0; j < state_count; j++) {
          final_multiply[j] = (final_multiply[j] + (init_vec[i] * square_vec[i][j]) % mod) % mod;
        }
      }

      for (long long num : final_multiply) {
        result = (result + num) % mod;
      }

      return result;
    }

    Matrix multiply(const Matrix& A, const Matrix& B) {
      int size = A.size();

      Matrix temp(size, vector<long long>(size));

      for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
          for (int k = 0; k < size; k++) {
            temp[i][j] = (temp[i][j] + A[i][k] * B[k][j]) % mod;
          }
        }
      }

      return temp;
    }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  int result = sol.zigZagArrays(3, 4, 5);
  int result_expected = 2;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.zigZagArrays(3, 1, 3);
  result_expected = 10;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}