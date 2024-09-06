#include<iostream>
using namespace std;

long long factorial(int n) {
    long long fact = 1;
    for(int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    cout << "The factorial of " << num << " is " << factorial(num) << endl;
    return 0;
}