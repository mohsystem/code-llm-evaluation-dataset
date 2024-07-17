#include <iostream>
#include <vector>
#include <string>

bool isValidWalk(std::vector<std::string> walk) {
    int x = 0, y = 0;
    for (std::string dir : walk) {
        if (dir == "n") y++;
        if (dir == "s") y--;
        if (dir == "e") x++;
        if (dir == "w") x--;
    }
    return x == 0 && y == 0 && walk.size() == 10;
}

int main() {
    std::vector<std::string> walk = {"n", "s", "e", "w", "n", "s", "e", "w", "n", "s"};
    std::cout << std::boolalpha << isValidWalk(walk) << std::endl;
    return 0;
}