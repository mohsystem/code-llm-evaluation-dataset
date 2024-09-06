#include <iostream>
#include <string>

std::string cpp_copy_string(const std::string& s) {
    return s;
}
std::string cpp_concat_strings(const std::string& s1, const std::string& s2) {
    return s1 + s2;
}

int main() {
    // C++ string operations
    std::string cppStr = "Hello, C++!";
    std::string cppCopiedStr = cpp_copy_string(cppStr);
    std::string cppConcatenatedStr = cpp_concat_strings(cppStr, " How are you?");

    // Output C++ strings
    std::cout << "C++ copied string: " << cppCopiedStr << std::endl;
    std::cout << "C++ concatenated string: " << cppConcatenatedStr << std::endl;

    return 0;
}