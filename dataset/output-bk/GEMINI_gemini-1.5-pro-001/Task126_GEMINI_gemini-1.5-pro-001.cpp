#include <iostream>
#include <string>

using namespace std;

int main() {
    string choice;
    cout << "Enter your destination (A/B/C): ";
    cin >> choice;

    if (choice == "A" || choice == "a") {
        cout << "https://www.exampleA.com" << endl;
    } else if (choice == "B" || choice == "b") {
        cout << "https://www.exampleB.com" << endl;
    } else if (choice == "C" || choice == "c") {
        cout << "https://www.exampleC.com" << endl;
    } else {
        cout << "Invalid choice." << endl;
    }

    return 0;
}