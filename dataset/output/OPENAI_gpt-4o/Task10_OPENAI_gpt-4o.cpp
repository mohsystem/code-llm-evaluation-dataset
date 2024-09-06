#include <iostream>
using namespace std;

int getSum(int a, int b) {
    if (a == b) return a;
    if (a > b) {
        int temp = a;
        a = b;
        b = temp;
    }
    int sum = 0;
    for (int i = a; i <= b; i++) {
        sum += i;
    }
    return sum;
}

int main() {
    int result = getSum(1, 0); // Example usage
    cout << result << endl;
    return 0;
}