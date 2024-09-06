#include <vector>

int number_of_people_still_on_bus(std::vector<std::pair<int, int>> lst) {
    int people_on_bus = 0;
    for (auto pair : lst) {
        people_on_bus += pair.first - pair.second;
    }
    return people_on_bus;
}