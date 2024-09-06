
#include <string>

bool solution(std::string const &str, std::string const &ending) {
    if (ending.length() > str.length()) return false;
    return std::equal(ending.rbegin(), ending.rend(), str.rbegin());
}
