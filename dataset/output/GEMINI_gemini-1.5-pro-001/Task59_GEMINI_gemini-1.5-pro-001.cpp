#include <string>
#include <iostream>
#include <algorithm>

std::string accum(const std::string &s){
    std::string result = "";
    for (int i = 0; i < s.length(); i++) {
        if (i > 0) {
          result += "-";
        }
        result += toupper(s[i]);
        for (int j = 0; j < i; j++) {
          result += tolower(s[i]);
        }
    }
    return result;
}

int main() {
    std::cout << accum("abcd") << std::endl;
    std::cout << accum("RqaEzty") << std::endl;
    std::cout << accum("cwAt") << std::endl;
    return 0;
}