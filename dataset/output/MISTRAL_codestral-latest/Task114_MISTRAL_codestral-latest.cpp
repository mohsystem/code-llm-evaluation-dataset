// C++
#include <iostream>
#include <string>

int main() {
    std::string str1 = "Hello, ";
    std::string str2 = "World!";

    // Copying a string
    std::string str3 = str1;
    std::cout << "Copied string: " << str3 << std::endl;

    // Concatenating strings
    std::string str4 = str1 + str2;
    std::cout << "Concatenated string: " << str4 << std::endl;

    // Manipulating strings
    std::string str5 = str4;
    size_t pos = str5.find("World");
    if (pos != std::string::npos)
        str5.replace(pos, 5, "C++");
    std::cout << "Manipulated string: " << str5 << std::endl;

    return 0;
}