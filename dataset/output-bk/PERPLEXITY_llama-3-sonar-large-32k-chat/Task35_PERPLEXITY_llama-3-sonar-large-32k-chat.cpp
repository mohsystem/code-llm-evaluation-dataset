#include <iostream>
#include <vector>

int peopleOnBus(std::vector<std::pair<int, int>>& stops) {
    int people = 0;
    for (auto& stop : stops) {
        people += stop.first - stop.second;
    }
    return people;
}

int main() {
    std::vector<std::pair<int, int>> stops = {{10, 0}, {3, 5}, {5, 8}};
    std::cout << peopleOnBus(stops) << std::endl;
    return 0;
}