#include <iostream>
#include <cmath>
using namespace std;
double cubeDiagonal(double volume) {
    return round(sqrt(3) * pow(volume, 1. / 3) * 100.) / 100.;
}
int main() {
    cout << fixed << setprecision(2) << cubeDiagonal(8) << endl;  // 3.46
    cout << fixed << setprecision(2) << cubeDiagonal(343) << endl;  // 12.12
    cout << fixed << setprecision(2) << cubeDiagonal(1157.625) << endl;  // 18.19
    return 0;
}