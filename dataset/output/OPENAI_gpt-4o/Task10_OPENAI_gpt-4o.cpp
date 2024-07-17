#include <iostream>
using namespace std;

int sum_integers(int a, int b) {
    int min = (a < b) ? a : b;
    int max = (a > b) ? a : b;
    int sum = 0;

    for (int i = min; i <= max; i++) {
        sum += i;
    }

    return sum;
}

int main() {
    cout << sum_integers(1, 0) << endl;  // 1
    cout << sum_integers(1, 2) << endl;  // 3
    cout << sum_integers(0, 1) << endl;  // 1
    cout << sum_integers(1, 1) << endl;  // 1
    cout << sum_integers(-1, 0) << endl;  // -1
    cout << sum_integers(-1, 2) << endl;  // 2

    return 0;
}