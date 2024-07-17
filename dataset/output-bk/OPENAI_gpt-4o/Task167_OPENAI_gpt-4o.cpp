#include <iostream>
#include <cmath>

using namespace std;

double cubeDiagonal(double volume) {
    double sideLength = cbrt(volume);
    double diagonal = sideLength * sqrt(3);
    return round(diagonal * 100.0) / 100.0;
}

int main() {
    cout << cubeDiagonal(8) << endl;         // ➞ 3.46
    cout << cubeDiagonal(343) << endl;       // ➞ 12.12
    cout << cubeDiagonal(1157.625) << endl;  // ➞ 18.19
    return 0;
}