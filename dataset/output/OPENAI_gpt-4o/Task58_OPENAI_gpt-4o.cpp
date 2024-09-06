#include <iostream>
#include <algorithm>

bool XO(const std::string &str) {
    std::string s = str;
    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    int xCount = std::count(s.begin(), s.end(), 'x');
    int oCount = std::count(s.begin(), s.end(), 'o');
    return xCount == oCount;
}

int main() {
    std::cout << std::boolalpha;
    std::cout << XO("ooxx") << std::endl;  // True
    std::cout << XO("xooxx") << std::endl;  // False
    std::cout << XO("ooxXm") << std::endl;  // True
    std::cout << XO("zpzpzpp") << std::endl;  // True
    std::cout << XO("zzoo") << std::endl;  // False
  
    return 0;
}