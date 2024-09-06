#include <string>
std::string tweakLetters(std::string word, int tweaks[]) {
    std::string result = "";
    for (int i = 0; i < word.length(); i++) {
        result += word[i] + tweaks[i];
    }
    return result;
}