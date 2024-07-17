#include <vector>
#include <string>

std::vector<std::string> buildTower(int nFloors) {
    std::vector<std::string> tower;
    for (int i = 0; i < nFloors; i++) {
        std::string floor(nFloors - i - 1, ' ');
        floor += std::string(2 * i + 1, '*');
        floor += std::string(nFloors - i - 1, ' ');
        tower.push_back(floor);
    }
    return tower;
}