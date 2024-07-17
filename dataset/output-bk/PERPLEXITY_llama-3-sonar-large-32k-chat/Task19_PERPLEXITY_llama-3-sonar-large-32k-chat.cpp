#include <iostream>
#include <string>
#include <sstream>

void reverseWords(std::string str) {
    std::istringstream iss(str);
    std::string word;
    while (iss >> word) {
        if (word.length() >= 5) {
            std::reverse(word.begin(), word.end());
        }
        std::cout << word << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::string str1 = "Hey fellow warriors";
    std::string str2 = "This is a test";
    std::string str3 = "This is another test";
    reverseWords(str1);
    reverseWords(str2);
    reverseWords(str3);
    return 0;
}