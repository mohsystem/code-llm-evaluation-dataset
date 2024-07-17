// C++
#include <iostream>
#include <cctype>

std::string toJadenCase(std::string phrase) {
    for (int i = 0; i < phrase.length(); i++) {
        if (i == 0 || phrase[i - 1] == ' ') {
            phrase[i] = std::toupper(phrase[i]);
        }
    }
    return phrase;
}

int main() {
    std::cout << toJadenCase("How can mirrors be real if our eyes aren't real");
    return 0;
}