
#include <iostream>
#include <vector>

class BusPassengers {
public:
    static int countPassengers(std::vector<std::vector<int>>& stops) {
        int passengers = 0;
        for (const auto& stop : stops) {
            passengers += stop[0] - stop[1];
        }
        return passengers;
    }
};

int main() {
    std::vector<std::vector<int>> stops = {{10,0}, {3,5}, {5,8}};
    std::cout << BusPassengers::countPassengers(stops) << std::endl;
    return 0;
}
