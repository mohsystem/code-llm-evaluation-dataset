#include<iostream>
using namespace std;

int main() {
    double num1, num2;
    char operator_;

    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter operator (+, -, *, /): ";
    cin >> operator_;

    cout << "Enter second number: ";
    cin >> num2;

    if (operator_ == '+') {
        cout << "Result: " << num1 + num2 << endl;
    } else if (operator_ == '-') {
        cout << "Result: " << num1 - num2 << endl;
    } else if (operator_ == '*') {
        cout << "Result: " << num1 * num2 << endl;
    } else if (operator_ == '/') {
        if (num2 != 0) {
            cout << "Result: " << num1 / num2 << endl;
        } else {
            cout << "Error Division by zero is not allowed." << endl;
        }
    } else {
        cout << "Invalid operator. Please enter either +, -, * or /." << endl;
    }

    return 0;
}