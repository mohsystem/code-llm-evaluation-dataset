
#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string str1 = "Hello";
    std::string str2 = "World";

    // Copy
    std::string copy = str1;

    // Concatenate
    std::string concat = str1 + " " + str2;

    // Manipulate
    std::string upper = concat;
    std::transform(upper.begin(), upper.end(), upper.begin(), ::toupper);

    std::string sub = concat.substr(0, 5);

    std::string replace = concat;
    std::replace(replace.begin(), replace.end(), \'o\', \'0\');

    std::cout << "Original: " << str1 << ", " << str2 << std::endl;
    std::cout << "Copy: " << copy << std::endl;
    std::cout << "Concatenated: " << concat << std::endl;
    std::cout << "Uppercase: " << upper << std::endl;
    std::cout << "Substring: " << sub << std::endl;
    std::cout << "Replaced: " << replace << std::endl;

    return 0;
}
