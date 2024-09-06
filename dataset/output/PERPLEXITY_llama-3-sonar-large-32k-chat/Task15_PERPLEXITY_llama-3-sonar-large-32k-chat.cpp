#include <vector>
#include <string>

std::vector<std::string> towerBuilder(int nFloors) {
    std::vector<std::string> tower;
    for (int i = 0; i < nFloors; i++) {
        std::string str;
        for (int j = 0; j < nFloors - i - 1; j++) {
            str += " ";
        }
        for (int j = 0; j < 2 * i + 1; j++) {
            str += "*";
        }
        for (int j = 0; j < nFloors - i - 1; j++) {
            str += " ";
        }
        tower.push_back(str);
    }
    return tower;
}