#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    string choice;

    cout << "Enter your destination (A, B, or C): ";
    cin >> choice;

    for (char &c : choice) {
        c = toupper(c);
    }

    if (choice == "A") {
        cout << "Redirecting to page A..." << endl;
    } else if (choice == "B") {
        cout << "Redirecting to page B..." << endl;
    } else if (choice == "C") {
        cout << "Redirecting to page C..." << endl;
    } else {
        cout << "Invalid choice. Please enter A, B, or C." << endl;
    }

    return 0;
}