#include <iostream>
using namespace std;

int persistence(long long num) {
    if (num < 10) {
        return 0;
    }
    int count = 0;
    while (num >= 10) {
        long long prod = 1;
        while (num > 0) {
            prod *= (num % 10);
            num /= 10;
        }
        num = prod;
        count++;
    }
    return count;
}

int main() {
    cout << persistence(39) << endl;
    cout << persistence(999) << endl;
    cout << persistence(4) << endl;
    return 0;
}