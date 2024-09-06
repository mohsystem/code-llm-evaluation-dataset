#include <iostream>
using namespace std;

int multiplyDigits(int num) {
    int result = 1;
    while (num > 0) {
        result *= num % 10;
        num /= 10;
    }
    return result;
}

int persistence(int num) {
    int count = 0;
    while (num >= 10) {
        num = multiplyDigits(num);
        count += 1;
    }
    return count;
}

int main() {
    cout << persistence(39) << endl;  // 3
    cout << persistence(999) << endl; // 4
    cout << persistence(4) << endl;   // 0

    return 0;
}