#include <vector>

int countPassengers(std::vector<std::vector<int>> stops) {
    int total = 0;
    for (const auto& stop : stops) {
        total += stop[0] - stop[1];
    }
    return total;
}