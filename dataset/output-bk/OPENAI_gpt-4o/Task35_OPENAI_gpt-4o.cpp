#include <iostream>
#include <vector>

int peopleOnBus(const std::vector<std::pair<int, int>>& busStops) {
    int people = 0;
    for (const auto& stop : busStops) {
        people += stop.first;
        people -= stop.second;
    }
    return people;
}

int main() {
    std::vector<std::pair<int, int>> busStops = {{3, 0}, {2, 1}, {5, 3}, {2, 2}};
    std::cout << peopleOnBus(busStops) << std::endl;
    return 0;
}