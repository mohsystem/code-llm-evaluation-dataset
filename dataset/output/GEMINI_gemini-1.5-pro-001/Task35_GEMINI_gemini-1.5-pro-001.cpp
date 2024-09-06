#include <vector>

int number(const std::vector<std::pair<int, int>>& busStops) {
  int peopleInBus = 0;
  for (const auto& stop : busStops) {
    peopleInBus += stop.first - stop.second;
  }
  return peopleInBus;
}