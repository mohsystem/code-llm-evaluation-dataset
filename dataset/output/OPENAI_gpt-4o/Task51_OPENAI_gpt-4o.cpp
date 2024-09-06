#include <iostream>
#include <string>
using namespace std;

string encrypt(string text) {
    string result = "";
    
    for (char &ch : text) {
        if (isupper(ch)) {
            result += char((ch + 1 - 'A') % 26 + 'A');
        } else if (islower(ch)) {
            result += char((ch + 1 - 'a') % 26 + 'a');
        } else {
            result += ch;
        }
    }
    return result;
}

int main() {
    string inputText = "HelloWorld";
    string encryptedText = encrypt(inputText);
    cout << encryptedText << endl;
    return 0;
}