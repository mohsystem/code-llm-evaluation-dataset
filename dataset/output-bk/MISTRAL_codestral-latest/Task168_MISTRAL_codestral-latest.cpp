#include <string>
#include <vector>
using namespace std;

string tweakLetters(string word, vector<int> tweaks) {
    string result = "";
    for (int i = 0; i < word.length(); i++) {
        char c = ((word[i] - 'a' + tweaks[i]) % 26) + 'a';
        result += c;
    }
    return result;
}