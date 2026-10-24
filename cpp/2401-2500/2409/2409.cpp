//
// Created by Milo on 10/24/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

class Solution {
 public:
  int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob,
                        string leaveBob) {
    int arrive_alice_d = calc_days(arriveAlice);
    int leave_alice_d = calc_days(leaveAlice);
    int arrive_bob_d = calc_days(arriveBob);
    int leave_bob_d = calc_days(leaveBob);
    int start = max(arrive_alice_d, arrive_bob_d);
    int end = min(leave_alice_d, leave_bob_d);
    return max(0, end - start + 1);
  }
  int calc_days(string date) {
    int month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int m = stoi(date.substr(0, 2));
    int d = stoi(date.substr(3, 2));
    int day = 0;
    for (int i = 0; i < m - 1; i++) {
      day += month[i];
    }
    return day + d;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  cout << "Test Case 1: " << endl;
  int result = sol.countDaysTogether("08-15", "08-18", "08-16", "08-19");
  int result_expected = 3;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  // Test Case 2
  cout << "Test Case 2: " << endl;
  result = sol.countDaysTogether("10-01", "10-31", "11-01", "12-31");
  result_expected = 0;
  assert(result == result_expected);
  cout << "PASSED" << endl;

  return 0;
}