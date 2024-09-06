#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int dig_pow(int n, int p) {
    string digits = to_string(n);
    int sum = 0;
    for (size_t i = 0; i < digits.length(); i++) {
        sum += pow(digits[i] - '0', p + i);
    }
    return sum % n == 0 ? sum / n : -1;
}

int main() {
    cout << dig_pow(89, 1) << endl;     // Output: 1
    cout << dig_pow(92, 1) << endl;     // Output: -1
    cout << dig_pow(695, 2) << endl;    // Output: 2
    cout << dig_pow(46288, 3) << endl;  // Output: 51
    return 0;
}