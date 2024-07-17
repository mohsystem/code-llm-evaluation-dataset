#include <iostream>
#include <vector>
#include <string>

int main() {
    int floors = 6;
    std::vector<std::string> tower(floors);
    for (int i = 0; i < floors; i++) {
        std::string floor;
        for (int j = 0; j < floors - i - 1; j++) {
            floor += " ";
        }
        for (int j = 0; j < 2 * i + 1; j++) {
            floor += "*";
        }
        for (int j = 0; j < floors - i - 1; j++) {
            floor += " ";
        }
        tower[i] = floor;
    }
    for (const std::string& floor : tower) {
        std::cout << floor << std::endl;
    }
    return 0;
}