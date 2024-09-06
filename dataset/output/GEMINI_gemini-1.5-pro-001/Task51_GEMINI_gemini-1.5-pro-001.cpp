#include <iostream>
#include <string>

using namespace std;

string encrypt(string text, int key) {
    string result = "";
    for (char ch : text) {
        if (isalpha(ch)) {
            char start = islower(ch) ? 'a' : 'A';
            char shiftedChar = (char)((ch - start + key) % 26 + start);
            result += shiftedChar;
        } else if (isdigit(ch)) {
            char shiftedChar = (char)(((ch - '0' + key) % 10) + '0');
            result += shiftedChar;
        } else {
            result += ch;
        }
    }
    return result;
}

int main() {
    string inputString = "Hello, world 123!";
    int encryptionKey = 3;
    string encryptedString = encrypt(inputString, encryptionKey);
    cout << "Encrypted: " << encryptedString << endl;
    return 0;
}