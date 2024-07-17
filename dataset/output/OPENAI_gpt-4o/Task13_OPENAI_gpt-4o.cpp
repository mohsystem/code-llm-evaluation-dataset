#include <iostream>
#include <vector>

bool isValid(std::vector<char> walk) {
    if (walk.size() != 10) return false;
    int x = 0, y = 0;
    for (char direction : walk) {
        switch (direction) {
            case 'n': y++; break;
            case 's': y--; break;
            case 'e': x++; break;
            case 'w': x--; break;
        }
    }
    return x == 0 && y == 0;
}

int main() {
    std::vector<char> walk = {'n', 's', 'n', 's', 'n', 's', 'n', 's', 'n', 's'};
    std::cout << (isValid(walk) ? "true" : "false") << std::endl; // should return true
    return 0;
}