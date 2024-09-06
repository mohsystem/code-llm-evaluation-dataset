
#include <vector>
#include <utility>

int number(const std::vector<std::pair<int, int>>& busStops) {
    int passengers = 0;
    for (const auto& stop : busStops) {
        passengers += stop.first - stop.second;
    }
    return passengers;
}
