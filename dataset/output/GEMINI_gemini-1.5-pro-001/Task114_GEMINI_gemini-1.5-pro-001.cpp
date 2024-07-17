#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string inputString, copiedString, concatenatedString, reversedString;

    cout << "Enter a string: ";
    getline(cin, inputString);

    // Copy the string
    copiedString = inputString;

    // Concatenate the string with itself
    concatenatedString = inputString + inputString;

    // Reverse the string
    reversedString = inputString;
    reverse(reversedString.begin(), reversedString.end());

    // Convert the string to uppercase
    transform(inputString.begin(), inputString.end(), inputString.begin(), ::toupper);

    // Convert the string to lowercase
    transform(inputString.begin(), inputString.end(), inputString.begin(), ::tolower);

    cout << "Copied string: " << copiedString << endl;
    cout << "Concatenated string: " << concatenatedString << endl;
    cout << "Reversed string: " << reversedString << endl;
    cout << "Uppercase string: " << inputString << endl;

    return 0;
}