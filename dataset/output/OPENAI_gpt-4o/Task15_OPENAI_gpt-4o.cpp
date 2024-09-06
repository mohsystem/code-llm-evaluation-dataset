#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> buildTower(int nFloors) {
    std::vector<std::string> tower;
    for (int i = 1; i <= nFloors; i++) {
        std::string padding = std::string(nFloors - i, ' ');
        std::string stars = std::string(2 * i - 1, '*');
        tower.push_back(padding + stars + padding);
    }
    return tower;
}

int main() {
    std::vector<std::string> tower = buildTower(6);
    for (const auto& floor : tower) {
        std::cout << floor << std::endl;
    }
    return 0;
}