#include <vector>
#include <string>

bool isValidWalk(std::vector<std::string> walk) {
    int n = 0, s = 0, e = 0, w = 0;
    for (std::string dir : walk) {
        if (dir == "n") n++;
        if (dir == "s") s++;
        if (dir == "e") e++;
        if (dir == "w") w++;
    }
    return walk.size() == 10 && n == s && e == w;
}