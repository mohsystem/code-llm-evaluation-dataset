#include <iostream>

using namespace std;

double calculate(double a, double b, char operator) {
    switch (operator) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        default:
            cout << "Invalid operator" << endl;
            return 0;
    }
}

int main() {
    double a, b;
    char operator;

    cout << "Enter first number: ";
    cin >> a;

    cout << "Enter second number: ";
    cin >> b;

    cout << "Enter operator (+, -, *, /): ";
    cin >> operator;

    cout << "Result: " << calculate(a, b, operator) << endl;

    return 0;
}