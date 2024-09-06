#include <iostream>
#include <vector>

bool isValidWalk(std::vector<char> walk) {
    if (walk.size() != 10) return false;
    int x = 0, y = 0;
    for (char direction : walk) {
        switch (direction) {
            case 'n': y += 1; break;
            case 's': y -= 1; break;
            case 'e': x += 1; break;
            case 'w': x -= 1; break;
        }
    }
    return x == 0 && y == 0;
}

int main() {
    std::vector<char> walk = {'n', 's', 'n', 's', 'n', 's', 'n', 's', 'n', 's'};
    std::cout << std::boolalpha << isValidWalk(walk) << std::endl; // Output: true
    return 0;
}