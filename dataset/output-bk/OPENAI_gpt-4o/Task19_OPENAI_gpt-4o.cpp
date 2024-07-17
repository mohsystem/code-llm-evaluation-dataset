// C++
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

string reverseWords(const string& str) {
    stringstream ss(str);
    string word;
    vector<string> words;

    while (ss >> word) {
        if (word.length() >= 5) {
            reverse(word.begin(), word.end());
        }
        words.push_back(word);
    }

    stringstream result;
    for (size_t i = 0; i < words.size(); i++) {
        result << words[i];
        if (i != words.size() - 1) {
            result << " ";
        }
    }
    return result.str();
}

int main() {
    string input = "Hey fellow warriors";
    cout << reverseWords(input) << endl;
    return 0;
}