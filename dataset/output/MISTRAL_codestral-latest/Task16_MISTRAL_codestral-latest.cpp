#include <string>

bool solution(const std::string &str, const std::string &ending) {
    if (ending.size() > str.size()) return false;
    return str.substr(str.size() - ending.size()) == ending;
}