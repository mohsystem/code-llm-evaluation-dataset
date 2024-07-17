#include <iostream>
#include <algorithm>

bool XO(const std::string& str) {
    int countX = std::count_if(str.begin(), str.end(), [](char ch) { return std::tolower(ch) == 'x'; });
    int countO = std::count_if(str.begin(), str.end(), [](char ch) { return std::tolower(ch) == 'o'; });
    return countX == countO;
}

int main() {
    std::cout << std::boolalpha << XO("ooxx") << std::endl;
    std::cout << std::boolalpha << XO("xooxx") << std::endl;
    std::cout << std::boolalpha << XO("ooxXm") << std::endl;
    std::cout << std::boolalpha << XO("zpzpzpp") << std::endl;
    std::cout << std::boolalpha << XO("zzoo") << std::endl;
    return 0;
}