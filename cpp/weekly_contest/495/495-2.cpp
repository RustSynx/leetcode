//
// Created by Milo on 3/29/26.
//
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

class EventManager {
 public:
  unordered_map<int, int> event_map;
  unordered_map<int, set<int>> priority_map;
  set<int, std::greater<>> priority_set;

  EventManager(vector<vector<int>>& events) {
    for (int i = 0; i < events.size(); i++) {
      int eventId = events[i][0];
      int priority = events[i][1];
      event_map.emplace(eventId, priority);
      priority_set.emplace(priority);
      priority_map[priority].emplace(eventId);
    }
  }

  void updatePriority(int eventId, int newPriority) {
    int prevPriority = event_map[eventId];
    priority_map[prevPriority].erase(eventId);
    if (priority_map[prevPriority].empty()) {
      priority_set.erase(prevPriority);
      priority_map.erase(prevPriority);
    }
    priority_set.emplace(newPriority);
    priority_map[newPriority].emplace(eventId);
    event_map[eventId] = newPriority;
  }

  int pollHighest() {
    if (priority_set.empty()) return -1;
    int priority = *priority_set.begin();
    int eventId = *priority_map[priority].begin();
    priority_map[priority].erase(eventId);
    if (priority_map[priority].empty()) {
      priority_set.erase(priority);
      priority_map.erase(priority);
    }
    event_map.erase(eventId);
    return eventId;
  }
};

int main() {
  vector<vector<int>> input = {{5, 7}, {2, 7}, {9, 4}};
  EventManager* obj = new EventManager(input);
  cout << obj->pollHighest() << endl;
  ;
  obj->updatePriority(9, 7);
  cout << obj->pollHighest() << endl;
  cout << obj->pollHighest() << endl;
  delete obj;

  input = {{4, 1}, {7, 2}};
  obj = new EventManager(input);
  cout << obj->pollHighest() << endl;
  cout << obj->pollHighest() << endl;
  cout << obj->pollHighest() << endl;
  delete obj;

  return 0;
}