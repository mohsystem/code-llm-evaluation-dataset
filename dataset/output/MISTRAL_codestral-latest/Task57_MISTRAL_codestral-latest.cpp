#include<iostream>
using namespace std;

long long factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "The factorial of " << n << " is " << factorial(n) << endl;
    return 0;
}