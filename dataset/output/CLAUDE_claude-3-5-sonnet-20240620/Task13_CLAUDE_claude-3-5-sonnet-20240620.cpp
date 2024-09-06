
#include <iostream>
#include <vector>

bool isValidWalk(std::vector<char> walk) {
    if (walk.size() != 10) {
        return false;
    }
    
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
    std::cout << std::boolalpha;
    std::cout << isValidWalk({'n','s','n','s','n','s','n','s','n','s'}) << std::endl;  // true
    std::cout << isValidWalk({'w','e','w','e','w','e','w','e','w','e','w','e'}) << std::endl;  // false
    std::cout << isValidWalk({'w'}) << std::endl;  // false
    std::cout << isValidWalk({'n','n','n','s','n','s','n','s','n','s'}) << std::endl;  // false
    return 0;
}
