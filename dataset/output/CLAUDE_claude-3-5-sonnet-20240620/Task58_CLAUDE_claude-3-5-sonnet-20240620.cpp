
#include <iostream>
#include <string>
#include <algorithm>

bool getXO(std::string str) {
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    return std::count(str.begin(), str.end(), \'x\') == std::count(str.begin(), str.end(), \'o\');
}

int main() {
    std::cout << std::boolalpha;
    std::cout << getXO("ooxx") << std::endl;
    std::cout << getXO("xooxx") << std::endl;
    std::cout << getXO("ooxXm") << std::endl;
    std::cout << getXO("zpzpzpp") << std::endl;
    std::cout << getXO("zzoo") << std::endl;
    return 0;
}
