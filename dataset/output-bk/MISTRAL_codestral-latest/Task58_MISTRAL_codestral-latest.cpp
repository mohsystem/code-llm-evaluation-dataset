#include <algorithm>
#include <string>

bool getXO (const std::string& str) {
    int x = std::count(str.begin(), str.end(), 'x');
    int o = std::count(str.begin(), str.end(), 'o');
    return x == o;
}