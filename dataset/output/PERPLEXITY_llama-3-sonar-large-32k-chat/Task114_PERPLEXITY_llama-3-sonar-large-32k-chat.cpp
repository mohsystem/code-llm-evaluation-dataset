#include <iostream>
#include <string>

int main() {
    std::string str1 = "Hello";
    std::string str2 = "World";
    
    // Copying a string
    std::string str3 = str1;
    std::cout << "Copied string: " << str3 << std::endl;
    
    // Concatenating strings
    std::string str4 = str1 + " " + str2;
    std::cout << "Concatenated string: " << str4 << std::endl;
    
    // Manipulating strings (upper case)
    for(char &c : str1) {
        c = toupper(c);
    }
    std::cout << "Upper case string: " << str1 << std::endl;
    
    // Manipulating strings (lower case)
    for(char &c : str2) {
        c = tolower(c);
    }
    std::cout << "Lower case string: " << str2 << std::endl;
    
    return 0;
}