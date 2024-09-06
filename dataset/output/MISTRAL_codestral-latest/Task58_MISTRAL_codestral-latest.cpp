#include <algorithm>
#include <string>

bool XO(const std::string& str) {
    std::string s = str;
    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    int x = std::count(s.begin(), s.end(), 'x');
    int o = std::count(s.begin(), s.end(), 'o');
    return x == o;
}