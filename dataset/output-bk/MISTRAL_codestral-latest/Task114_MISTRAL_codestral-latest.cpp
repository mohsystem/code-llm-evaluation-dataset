#include <iostream>
#include <cstring>

int main() {
    // Copying a string
    char str1[] = "Hello";
    char str2[10];
    strcpy(str2, str1);
    std::cout << "Copied string: " << str2 << std::endl;

    // Concatenating strings
    char str3[] = " World";
    strcat(str1, str3);
    std::cout << "Concatenated string: " << str1 << std::endl;

    // Manipulating strings
    std::string str4 = "C++ Programming";
    std::cout << "Length of the string: " << str4.length() << std::endl;
    std::cout << "Substring: " << str4.substr(4) << std::endl;
    std::cout << "Uppercase: " << std::uppercase << str4 << std::endl;
    std::cout << "Lowercase: " << std::nouppercase << str4 << std::endl;

    return 0;
}