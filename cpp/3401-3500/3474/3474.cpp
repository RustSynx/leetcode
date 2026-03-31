//
// Created by Milo on 3/31/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string generateString(string str1, string str2) {
        int n = static_cast<int>(str1.length());
        int m = static_cast<int>(str2.length());
        string result(n + m - 1, '0');
        vector<bool> true_position(n + m - 1, false);
        int max_filled = 0;
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'T') {
                int start = max(0, max_filled - i);
                for (int j = start; j < m; j++) {
                    result[i + j] = str2[j];
                    true_position[i + j] = true;
                }
                max_filled = max(max_filled, i + m);
            }
        }
        for (int i = 0; i < n + m - 1; i++) {
            if (result[i] == '0') {
                result[i] = 'a';
            }
        }
        string_view s2_view(str2);
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'T') {
                if (string_view(result).substr(i, m) != s2_view) {
                    return "";
                }
            }
        }
        int i = 0;
        while (i < n) {
            if (str1[i] == 'F') {
                if (string_view(result).substr(i, m) == s2_view) {
                    int k = i + m - 1;
                    while (true) {
                        while (k >= i && true_position[k]) {
                            k--;
                        }
                        if (k < i) return "";
                        result[k]++;
                        if (result[k] > 'z') {
                            result[k] = 'a';
                            k--;
                        } else {
                            break;
                        }
                    }
                    for (int j = k + 1; j < n + m - 1; j++) {
                        if (!true_position[j]) {
                            result[j] = 'a';
                        }
                    }
                    i = max(0, k - m + 1);
                    continue;
                }
            }
            i++;
        }
        return result;
    }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  string result = sol.generateString("TFTF", "ab");
  string result_expected = "ababa";
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.generateString("TFTF", "abc");
  result_expected = "";
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  result = sol.generateString("F", "d");
  result_expected = "a";
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}