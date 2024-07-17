#include <iostream>
#include <string>

using namespace std;

int main() {
    string inputString;
    string concatenatedString;

    while (true) {
        cout << "Enter a string (or type 'quit' to exit): ";
        getline(cin, inputString);

        if (inputString == "quit") {
            break;
        }

        concatenatedString += inputString;
    }

    cout << "Concatenated string: " << concatenatedString << endl;

    return 0;
}
