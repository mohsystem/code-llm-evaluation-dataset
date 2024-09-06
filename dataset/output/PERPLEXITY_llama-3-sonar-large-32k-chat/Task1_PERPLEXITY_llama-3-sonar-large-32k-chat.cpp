#include <vector>

int number_of_people_still_on_bus(std::vector<std::pair<int, int>> people) {
    int count = 0;
    for (auto pair : people) {
        count += pair.first - pair.second;
    }
    return count;
}