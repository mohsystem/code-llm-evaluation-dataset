#include <iostream>
#include <limits>

using namespace std;

int main() {
    int integerInput;
    double doubleInput;

    // Get an integer from the user
    cout << "Enter an integer: ";
    while (!(cin >> integerInput) || integerInput <= 0) {
        cout << "Invalid input. Please enter a positive integer: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '
');
    }

    // Get a double from the user
    cout << "Enter a double: ";
    while (!(cin >> doubleInput) || doubleInput <= 0) {
        cout << "Invalid input. Please enter a positive double: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '
');
    }

    // Perform some operations on the input
    int sum = integerInput + (int)doubleInput;
    double product = integerInput * doubleInput;

    cout << "Sum: " << sum << endl;
    cout << "Product: " << product << endl;

    return 0;
}