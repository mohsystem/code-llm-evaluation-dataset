#include <vector>

int number(const std::vector<std::pair<int, int>>& bus_stops) {
  int people_on_bus = 0;
  for (const auto& stop : bus_stops) {
    people_on_bus += stop.first - stop.second;
  }
  return people_on_bus;
}