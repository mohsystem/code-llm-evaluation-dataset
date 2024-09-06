#include <iostream>
#include <sstream>
#include <cctype>
#include <string>
using namespace std;

string toJadenCase(string phrase) {
    if (phrase.empty()) {
        return "";
    }
    istringstream stream(phrase);
    string word;
    string jadenCase = "";
    while (stream >> word) {
        word[0] = toupper(word[0]);
        jadenCase += word + " ";
    }
    if (!jadenCase.empty()) {
        jadenCase.pop_back(); // Remove trailing space
    }
    return jadenCase;
}

int main() {
    cout << toJadenCase("How can mirrors be real if our eyes aren't real") << endl;
    return 0;
}