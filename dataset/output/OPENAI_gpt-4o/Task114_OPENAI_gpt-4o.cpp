// C++
#include <iostream>
#include <algorithm>
#include <cctype>

void cpp_string_operations() {
    std::string str1 = "Hello";
    std::string str2 = "World";
    std::string copied_str = str1;
    std::string concatenated_str = str1 + " " + str2;
    std::reverse(str1.begin(), str1.end());
    std::transform(str2.begin(), str2.end(), str2.begin(), ::toupper);
    std::cout << "C++ - Copied: " << copied_str << std::endl;
    std::cout << "C++ - Concatenated: " << concatenated_str << std::endl;
    std::cout << "C++ - Manipulated: " << str1 << " " << str2 << std::endl;
}

int main() {
    cpp_string_operations();
    return 0;
}