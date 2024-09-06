
#include <iostream>
#include <string>
#include <algorithm>

void string_operations() {
    // String copy
    std::string original = "Hello, World!";
    std::string copied = original;
    std::cout << "Original: " << original << std::endl;
    std::cout << "Copied: " << copied << std::endl;

    // String concatenation
    std::string str1 = "C++ ";
    std::string str2 = "is awesome!";
    std::string concatenated = str1 + str2;
    std::cout << "Concatenated: " << concatenated << std::endl;

    // String manipulation
    std::string text = "   C++ Programming   ";
    std::string stripped = text;
    stripped.erase(0, stripped.find_first_not_of(" "));
    stripped.erase(stripped.find_last_not_of(" ") + 1);
    
    std::string upper = text;
    std::transform(upper.begin(), upper.end(), upper.begin(), ::toupper);
    
    std::string lower = text;
    std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
    
    std::string replaced = text;
    size_t pos = replaced.find("C++");
    if (pos != std::string::npos) {
        replaced.replace(pos, 3, "Java");
    }

    std::cout << "Stripped: '" << stripped << "'" << std::endl;
    std::cout << "Uppercase: " << upper << std::endl;
    std::cout << "Lowercase: " << lower << std::endl;
    std::cout << "Replaced: " << replaced << std::endl;
}

int main() {
    string_operations();
    return 0;
}
