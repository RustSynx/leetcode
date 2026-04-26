//
// Created by Milo on 4/26/26.
//
#include <cassert>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  string sortVowels(string s) {
    unordered_map<char, int> vowels;
    vector<pair<char, int>> vowels_cnt;
    vowels_cnt.reserve(5);
    int n = static_cast<int>(s.length());
    int total_vowels = 0;
    for (int i = 0; i < n; i++) {
      if (checkVowels(s[i])) {
        if (!vowels.contains(s[i])) {
          vowels_cnt.push_back(make_pair(s[i], 1));
          vowels[s[i]] = vowels_cnt.size() - 1;
        } else {
          vowels_cnt[vowels[s[i]]].second++;
        }
        total_vowels++;
      }
    }
    vector<char> vowels_order;
    vowels_order.reserve(total_vowels);
    sort(vowels_cnt.begin(), vowels_cnt.end(),
         [](const pair<char, int>& a, const pair<char, int>& b) {
           return a.second > b.second;
         });
    int cnt_idx = 0;
    for (int i = 0; i < total_vowels; i++) {
      if (vowels_cnt[cnt_idx].second <= 0) cnt_idx++;
      vowels_order[i] = vowels_cnt[cnt_idx].first;
      vowels_cnt[cnt_idx].second--;
    }
    string result;
    result.reserve(n);
    cnt_idx = 0;
    for (int i = 0; i < n; i++) {
      int find_idx = findIdx(s[i]);
      if (find_idx != -1) {
        result.push_back(vowels_order[cnt_idx]);
        cnt_idx++;
      } else {
        result.push_back(s[i]);
      }
    }
    cout << result << endl;
    return result;
  }
  bool checkVowels(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
  }
  int findIdx(char c) {
    switch (c) {
      case 'a':
        return 0;
      case 'e':
        return 1;
      case 'i':
        return 2;
      case 'o':
        return 3;
      case 'u':
        return 4;
    }
    return -1;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  string result = sol.sortVowels("leetcode");
  string result_expected = "leetcedo";
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.sortVowels("aeiaaioooa");
  result_expected = "aaaaoooiie";
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  result = sol.sortVowels("baeiou");
  result_expected = "baeiou";
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  result = sol.sortVowels("oes");
  result_expected = "oes";
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}