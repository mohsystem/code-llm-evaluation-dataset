#include <iostream>
#include <limits>

using namespace std;

int main() {
    int num1, num2;

    cout << "Enter first number: ";
    while (!(cin >> num1)) {
        cout << "Invalid input. Please enter numbers only: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '
');
    }

    cout << "Enter second number: ";
    while (!(cin >> num2)) {
        cout << "Invalid input. Please enter numbers only: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '
');
    }

    int sum = num1 + num2;
    int difference = num1 - num2;
    int product = num1 * num2;

    cout << "Sum: " << sum << endl;
    cout << "Difference: " << difference << endl;
    cout << "Product: " << product << endl;

    if (num2 == 0) {
        cout << "Cannot divide by zero." << endl;
    } else {
        double quotient = (double)num1 / num2;
        cout << "Quotient: " << quotient << endl;
    }

    return 0;
}