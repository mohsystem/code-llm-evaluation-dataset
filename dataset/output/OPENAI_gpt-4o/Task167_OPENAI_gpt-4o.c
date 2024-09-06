#include <stdio.h>
#include <math.h>

double cubeDiagonal(double volume) {
    double side_length = cbrt(volume);
    double diagonal_length = side_length * sqrt(3);
    return round(diagonal_length * 100.0) / 100.0;
}

int main() {
    printf("%.2f\n", cubeDiagonal(8));
    printf("%.2f\n", cubeDiagonal(343));
    printf("%.2f\n", cubeDiagonal(1157.625));
    return 0;
}