#include <iostream>
using namespace std;

int main() {
    int number;
    cout << "Enter an integer: ";
    if (!(cin >> number)) {
        cout << "Invalid input. Please enter an integer." << endl;
        return 1;
    }
    cout << "The entered integer is: " << number << endl;
    return 0;
}