//
// Created by Milo on 9/13/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
    int n = img1.size();
    vector<pair<int, int>> img1_pairs;
    vector<pair<int, int>> img2_pairs;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (img1[i][j] == 1) {
          img1_pairs.push_back({i, j});
        }
        if (img2[i][j] == 1) {
          img2_pairs.push_back({i, j});
        }
      }
    }
    int result = 0;
    unordered_map<int, int> count;
    for (int i = 0; i < img1_pairs.size(); i++) {
      int x = img1_pairs[i].first;
      int y = img1_pairs[i].second;
      for (int j = 0; j < img2_pairs.size(); j++) {
        int dx = x - img2_pairs[j].first;
        int dy = y - img2_pairs[j].second;
        int key = (dx + 30) * 100 + (dy + 30);
        count[key]++;
      }
    }
    for (auto [k, v] : count) {
      result = max(result, v);
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<vector<int>> img1 = {{1, 1, 0}, {0, 1, 0}, {0, 1, 0}};
  vector<vector<int>> img2 = {{0, 0, 0}, {0, 1, 1}, {0, 0, 1}};
  int result = sol.largestOverlap(img1, img2);
  int result_expected = 3;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  img1 = {{1}};
  img2 = {{1}};
  result = sol.largestOverlap(img1, img2);
  result_expected = 1;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 3
  cout << "Test Case 3: " << endl;
  img1 = {{0}};
  img2 = {{0}};
  result = sol.largestOverlap(img1, img2);
  result_expected = 0;
  cout << "result : " << result << endl;
  cout << "result_expected : " << result_expected << endl;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}