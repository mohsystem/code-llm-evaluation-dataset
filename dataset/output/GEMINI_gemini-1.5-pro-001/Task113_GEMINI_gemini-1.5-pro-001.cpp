#include <iostream>
#include <string>

using namespace std;

int main() {
    int numStrings;
    string concatenatedString = "";

    cout << "Enter the number of strings: ";
    cin >> numStrings;
    cin.ignore(); // Consume newline character

    for (int i = 0; i < numStrings; i++) {
        string userString;
        cout << "Enter string " << i + 1 << ": ";
        getline(cin, userString);
        concatenatedString += userString;
    }
    cout << "Concatenated string: " << concatenatedString << endl;
    return 0;
}