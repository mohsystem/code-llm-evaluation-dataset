code here:
#include <iostream>
#include <string>

using namespace std;

int main() {
    string s1 = "Hello";
    string s2 = "World";
    cout << "Original Strings:" << endl;
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;

    // Copying a string
    string s3 = s1;
    cout << "\nCopied String:" << endl;
    cout << "s3: " << s3 << endl;

    // Concatenating strings
    string s4 = s1 + " " + s2;
    cout << "\nConcatenated String:" << endl;
    cout << "s4: " << s4 << endl;

    // Manipulating strings (upper case)
    string s5 = s1;
    for(int i = 0; i < s5.length(); i++) {
        s5[i] = toupper(s5[i]);
    }
    cout << "\nUpper Case String:" << endl;
    cout << "s5: " << s5 << endl;

    // Manipulating strings (lower case)
    string s6 = s2;
    for(int i = 0; i < s6.length(); i++) {
        s6[i] = tolower(s6[i]);
    }
    cout << "\nLower Case String:" << endl;
    cout << "s6: " << s6 << endl;

    return 0;
}