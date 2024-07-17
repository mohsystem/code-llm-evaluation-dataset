// C++
#include <vector>
#include <string>

bool isValidWalk(const std::vector<char>& walk) {
    if (walk.size() != 10) return false;
    int x = 0, y = 0;
    for (char dir : walk) {
        switch (dir) {
            case 'n': y++; break;
            case 's': y--; break;
            case 'e': x++; break;
            case 'w': x--; break;
        }
    }
    return x == 0 && y == 0;
}