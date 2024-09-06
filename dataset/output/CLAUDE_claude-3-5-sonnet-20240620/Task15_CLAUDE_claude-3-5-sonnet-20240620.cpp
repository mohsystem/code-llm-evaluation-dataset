
#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> towerBuilder(int nFloors) {
    std::vector<std::string> tower;
    for (int i = 0; i < nFloors; i++) {
        std::string spaces(nFloors - i - 1, ' ');
        std::string stars(2 * i + 1, '*');
        tower.push_back(spaces + stars + spaces);
    }
    return tower;
}

int main() {
    auto tower3 = towerBuilder(3);
    for (const auto& floor : tower3) {
        std::cout << floor << std::endl;
    }
    std::cout << std::endl;

    auto tower6 = towerBuilder(6);
    for (const auto& floor : tower6) {
        std::cout << floor << std::endl;
    }
    return 0;
}
