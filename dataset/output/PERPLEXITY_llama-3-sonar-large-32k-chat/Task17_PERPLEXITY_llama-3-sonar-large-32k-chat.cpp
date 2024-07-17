#include <iostream>
#include <string>
#include <cctype>

std::string toJadenCase(std::string phrase) {
    if (phrase.empty()) return "";
    for (int i = 0; i < phrase.length(); i++) {
        if (i == 0 || phrase[i-1] == ' ') {
            phrase[i] = toupper(phrase[i]);
        } else {
            phrase[i] = tolower(phrase[i]);
        }
    }
    return phrase;
}

int main() {
    std::string phrase = "How can mirrors be real if our eyes aren't real";
    std::string jadenCase = toJadenCase(phrase);
    std::cout << jadenCase << std::endl;
    return 0;
}