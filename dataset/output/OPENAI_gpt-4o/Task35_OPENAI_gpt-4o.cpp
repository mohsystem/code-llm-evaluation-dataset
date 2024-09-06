#include <iostream>
#include <vector>

int numberOfPeople(const std::vector<std::pair<int, int>>& busStops) {
    int totalPeople = 0;
    for (const auto& stop : busStops) {
        totalPeople += stop.first;
        totalPeople -= stop.second;
    }
    return totalPeople;
}

int main() {
    std::vector<std::pair<int, int>> busStops = {{10, 0}, {3, 5}, {5, 8}};
    std::cout << numberOfPeople(busStops) << std::endl; // Output: 5
    return 0;
}