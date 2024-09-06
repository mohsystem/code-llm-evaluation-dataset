
#include <iostream>
#include <string>

using namespace std;

string encrypt(string text, int shift) {
    string result = "";
    for (char& c : text) {
        if (isalpha(c)) {
            char asciiOffset = isupper(c) ? 65 : 97;
            result += char((c - asciiOffset + shift) % 26 + asciiOffset);
        } else {
            result += c;
        }
    }
    return result;
}

int main() {
    string text;
    int shift;
    
    cout << "Enter text to encrypt: ";
    getline(cin, text);
    cout << "Enter shift value: ";
    cin >> shift;
    
    string encryptedText = encrypt(text, shift);
    cout << "Encrypted text: " << encryptedText << endl;
    
    return 0;
}
