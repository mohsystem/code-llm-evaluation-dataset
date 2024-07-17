#include <iostream>
#include <string>

void buildTower(int nFloors) {
    for (int i = 0; i < nFloors; i++) {
        std::string floor(nFloors - i - 1, ' ') + std::string(2 * i + 1, '*') + std::string(nFloors - i - 1, ' ');
        std::cout << floor << std::endl;
    }
}

int main() {
    buildTower(3);
    buildTower(6);
    return 0;
}