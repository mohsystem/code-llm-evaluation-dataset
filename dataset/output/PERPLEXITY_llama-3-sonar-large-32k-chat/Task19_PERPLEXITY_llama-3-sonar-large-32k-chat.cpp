#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::string reverseWords(std::string s) {
    std::string word;
    std::vector<std::string> words;
    for (char c : s) {
        if (c == ' ') {
            if (word.length() >= 5) {
                std::reverse(word.begin(), word.end());
            }
            words.push_back(word);
            word = "";
        } else {
            word += c;
        }
    }
    if (word.length() >= 5) {
        std::reverse(word.begin(), word.end());
    }
    words.push_back(word);
    word = "";
    for (std::string w : words) {
        word += w + " ";
    }
    word.pop_back();
    return word;
}

int main() {
    std::cout << reverseWords("Hey fellow warriors") << std::endl;
    std::cout << reverseWords("This is a test") << std::endl;
    std::cout << reverseWords("This is another test") << std::endl;
    return 0;
}