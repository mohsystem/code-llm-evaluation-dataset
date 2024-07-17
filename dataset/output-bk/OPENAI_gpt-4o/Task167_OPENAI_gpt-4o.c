#include <stdio.h>
#include <math.h>

double cubeDiagonal(double volume) {
    double sideLength = cbrt(volume);
    double diagonal = sideLength * sqrt(3);
    return round(diagonal * 100.0) / 100.0;
}

int main() {
    printf("%.2f
", cubeDiagonal(8));         // ➞ 3.46
    printf("%.2f
", cubeDiagonal(343));       // ➞ 12.12
    printf("%.2f
", cubeDiagonal(1157.625));  // ➞ 18.19
    return 0;
}