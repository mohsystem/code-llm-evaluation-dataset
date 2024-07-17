
#include <iostream>
#include <vector>
#include <string>

class Kata {
public:
    static std::vector<std::string> towerBuilder(int nFloors) {
        std::vector<std::string> tower;
        for (int i = 0; i < nFloors; i++) {
            std::string floor(2 * nFloors - 1, \' \');
            for (int j = nFloors - i - 1; j < nFloors + i; j++) {
                floor[j] = \'*\';
            }
            tower.push_back(floor);
        }
        return tower;
    }
};

int main() {
    std::vector<std::string> tower = Kata::towerBuilder(6);
    for (const auto& floor : tower) {
        std::cout << floor << std::endl;
    }
    return 0;
}
