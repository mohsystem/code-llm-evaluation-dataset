#include <stdio.h>
#include <math.h>
double cubeDiagonal(double volume) {
    return round(sqrt(3) * pow(volume, 1. / 3) * 100.0) / 100.0;
}
int main() {
    printf("%.2f\n", cubeDiagonal(8));
    printf("%.2f\n", cubeDiagonal(343));
    printf("%.2f\n", cubeDiagonal(1157.625));
    return 0;
}