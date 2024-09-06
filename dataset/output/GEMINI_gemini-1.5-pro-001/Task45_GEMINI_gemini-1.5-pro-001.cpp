#include <iostream>
#include <limits>

using namespace std;

int getIntegerInput(const string& prompt) {
    while (true) {
        int input;
        cout << prompt;
        if (cin >> input) {
            return input;
        } else {
            cout << "Invalid input. Please enter an integer." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

double performOperation(int choice, int num1, int num2) {
    switch (choice) {
        case 1:
            return num1 + num2;
        case 2:
            return num1 - num2;
        case 3:
            return num1 * num2;
        case 4:
            if (num2 == 0) {
                throw runtime_error("Cannot divide by zero.");
            }
            return static_cast<double>(num1) / num2;
        default:
            throw invalid_argument("Invalid choice.");
    }
}

int main() {
    while (true) {
        cout << "\nMenu:" << endl;
        cout << "1. Addition" << endl;
        cout << "2. Subtraction" << endl;
        cout << "3. Multiplication" << endl;
        cout << "4. Division" << endl;
        cout << "5. Exit" << endl;

        try {
            int choice = getIntegerInput("Enter your choice (1-5): ");

            if (choice == 5) {
                break;
            }

            if (choice >= 1 && choice <= 4) {
                int num1 = getIntegerInput("Enter the first number: ");
                int num2 = getIntegerInput("Enter the second number: ");

                double result = performOperation(choice, num1, num2);
                cout << "Result: " << result << endl;
            } else {
                cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
            }
        } catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
        }
    }

    return 0;
}