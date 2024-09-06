#include <iostream>
#include <limits>

using namespace std;

int getIntegerInput(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value) {
            return value;
        } else {
            cout << "Invalid input. Please enter an integer." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

int main() {
    int num1 = getIntegerInput("Enter the first number: ");
    int num2 = getIntegerInput("Enter the second number: ");

    int sum = num1 + num2;
    int difference = num1 - num2;
    int product = num1 * num2;

    cout << "The sum is: " << sum << endl;
    cout << "The difference is: " << difference << endl;
    cout << "The product is: " << product << endl;

    return 0;
}