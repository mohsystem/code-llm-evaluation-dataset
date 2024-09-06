#include <iostream>
#include <cmath>
#include <iomanip>

double cubeDiagonal(double volume) {
    double side_length = cbrt(volume);
    double diagonal_length = side_length * sqrt(3);
    return round(diagonal_length * 100.0) / 100.0;
}

int main() {
    std::cout << std::fixed << std::setprecision(2) << cubeDiagonal(8) << std::endl;
    std::cout << std::fixed << std::setprecision(2) << cubeDiagonal(343) << std::endl;
    std::cout << std::fixed << std::setprecision(2) << cubeDiagonal(1157.625) << std::endl;
    return 0;
}