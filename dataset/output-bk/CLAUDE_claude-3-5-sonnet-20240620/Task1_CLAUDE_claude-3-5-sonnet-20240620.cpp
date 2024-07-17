
#include <iostream>
#include <vector>

int countPassengers(std::vector<std::pair<int, int>>& stops) {
    int passengers = 0;
    for (const auto& stop : stops) {
        passengers += stop.first - stop.second;
    }
    return passengers;
}

int main() {
    std::vector<std::pair<int, int>> stops = {{10, 0}, {3, 5}, {2, 5}};
    std::cout << countPassengers(stops) << std::endl;  // Output: 5
    return 0;
}
