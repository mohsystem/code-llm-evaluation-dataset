
#include <iostream>
#include <cmath>
#include <iomanip>

double cubeDiagonal(double volume) {
    double side = std::cbrt(volume);
    double diagonal = std::sqrt(3) * side;
    return std::round(diagonal * 100.0) / 100.0;
}

int main() {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << cubeDiagonal(8) << std::endl;
    std::cout << cubeDiagonal(343) << std::endl;
    std::cout << cubeDiagonal(1157.625) << std::endl;
    return 0;
}
