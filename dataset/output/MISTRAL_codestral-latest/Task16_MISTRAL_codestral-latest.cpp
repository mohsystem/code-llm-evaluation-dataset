#include <string>

bool solution(std::string mainString, std::string ending) {
    return mainString.size() >= ending.size() &&
           mainString.compare(mainString.size() - ending.size(), ending.size(), ending) == 0;
}