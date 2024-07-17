#include <iostream>
#include <vector>

int peopleOnTheBus(const std::vector<std::pair<int, int>>& stops) {
    int peopleOnBus = 0;
    for (const auto& stop : stops) {
        peopleOnBus += stop.first - stop.second;
    }
    return peopleOnBus;
}

int main() {
    std::vector<std::pair<int, int>> stops = {{10, 0}, {3, 5}, {2, 5}};
    std::cout << peopleOnTheBus(stops) << std::endl; // Output should be 5
    return 0;
}