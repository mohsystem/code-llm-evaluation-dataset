#include <iostream>
using namespace std;

int sumBetween(int a, int b) {
    int min = (a < b) ? a : b;
    int max = (a > b) ? a : b;
    int sum = 0;
    for (int i = min; i <= max; i++) {
        sum += i;
    }
    return sum;
}

int main() {
    cout << sumBetween(1, 0) << endl;
    cout << sumBetween(1, 2) << endl;
    cout << sumBetween(0, 1) << endl;
    cout << sumBetween(1, 1) << endl;
    cout << sumBetween(-1, 0) << endl;
    cout << sumBetween(-1, 2) << endl;
    return 0;
}