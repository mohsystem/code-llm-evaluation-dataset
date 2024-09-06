#include <iostream>
#include <vector>

int numberOfPeopleOnBus(const std::vector<std::pair<int, int>>& busStops) {
    int peopleOnBus = 0;
    for (const auto& stop : busStops) {
        peopleOnBus += stop.first - stop.second;
    }
    return peopleOnBus;
}

int main() {
    std::vector<std::pair<int, int>> busStops = { {3, 0}, {2, 1}, {5, 2}, {1, 4} };
    std::cout << numberOfPeopleOnBus(busStops) << std::endl;
    return 0;
}