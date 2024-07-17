#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string input;
    int number;

    cout << "Enter a number: ";
    getline(cin, input);

    stringstream ss(input);
    if (ss >> number) {
        cout << "You entered: " << number << endl;
    } else {
        cout << "Invalid input. Please enter a valid integer." << endl;
    }

    return 0;
}