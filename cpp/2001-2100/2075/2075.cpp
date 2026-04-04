//
// Created by Milo on 4/4/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

class Solution {
public:
  string decodeCiphertext(string encodedText, int rows) {
    int text_size = static_cast<int>(encodedText.length());
    if (text_size == 0) return "";
    int col_size = text_size / rows;
    string result = "";
    result.reserve(text_size);
    for (int i = 0; i < col_size; i++) {
      for (int j = 0; j < rows; j++) {
        if (i + j >= col_size) break;
        int index = i + j + j * col_size;
        if (index >= encodedText.length()) break;
        result.push_back(encodedText[index]);
      }
    }
    int end = result.find_last_not_of(" ");
    return result.substr(0, end + 1);
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  string result = sol.decodeCiphertext("ch   ie   pr", 3);
  string result_expected = "cipher";
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.decodeCiphertext("iveo    eed   l te   olc", 4);
  result_expected = "i love leetcode";
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  result = sol.decodeCiphertext("coding", 1);
  result_expected = "coding";
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}