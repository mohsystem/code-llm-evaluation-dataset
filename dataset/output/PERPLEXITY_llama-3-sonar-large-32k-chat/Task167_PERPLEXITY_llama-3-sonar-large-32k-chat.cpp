#include <iostream>
#include <cmath>
using namespace std;
double cubeDiagonal(double volume) {
    return round(sqrt(3) * pow(volume, 1. / 3) * 100.0) / 100.0;
}
int main() {
    cout << cubeDiagonal(8) << endl;
    cout << cubeDiagonal(343) << endl;
    cout << cubeDiagonal(1157.625) << endl;
    return 0;
}