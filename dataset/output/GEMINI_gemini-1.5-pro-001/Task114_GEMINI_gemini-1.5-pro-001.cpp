#include <iostream>
#include <string>

using namespace std;

int main() {
    // String declaration and initialization
    string str1 = "Hello";
    string str2 = "World";

    // String concatenation
    string concatenatedString = str1 + " " + str2;
    cout << "Concatenated String: " << concatenatedString << endl;

    // String copying
    string copiedString = str1;
    cout << "Copied String: " << copiedString << endl;

    // String length
    int length = concatenatedString.length();
    cout << "Length of Concatenated String: " << length << endl;

    // String manipulation - uppercase
    string uppercaseString = concatenatedString;
    for (char &c: uppercaseString) {
        c = toupper(c);
    }
    cout << "Uppercase String: " << uppercaseString << endl;

    // String manipulation - lowercase
    string lowercaseString = concatenatedString;
    for (char &c: lowercaseString) {
        c = tolower(c);
    }
    cout << "Lowercase String: " << lowercaseString << endl;

    // Substring extraction
    string substring = concatenatedString.substr(0, 5);
    cout << "Substring: " << substring << endl;

    return 0;
}