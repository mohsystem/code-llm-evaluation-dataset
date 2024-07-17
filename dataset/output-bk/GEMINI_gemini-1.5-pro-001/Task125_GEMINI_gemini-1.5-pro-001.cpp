#include <iostream>
#include <string>

using namespace std;

int main() {
    string userInput;

    cout << "Enter your choice: ";
    cin >> userInput;

    if (userInput == "option1") {
        cout << "Accessing resource 1..." << endl;
    } else if (userInput == "option2") {
        cout << "Accessing resource 2..." << endl;
    } else {
        cout << "Invalid choice." << endl;
    }

    return 0;
}