#include <vector>
#include <string>

std::vector<std::string> towerBuilder(int nFloors) {
    std::vector<std::string> tower;
    for (int i = 0; i < nFloors; i++) {
        tower.push_back(std::string(nFloors - i - 1, ' ') + std::string(2 * i + 1, '*') + std::string(nFloors - i - 1, ' '));
    }
    return tower;
}