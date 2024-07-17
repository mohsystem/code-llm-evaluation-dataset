#include <stdio.h>
#include <math.h>
double cubeDiagonal(double volume) {
    return round(sqrt(3) * pow(volume, 1. / 3) * 100.) / 100.;
}
int main() {
    printf("%.2f
", cubeDiagonal(8));  // 3.46
    printf("%.2f
", cubeDiagonal(343));  // 12.12
    printf("%.2f
", cubeDiagonal(1157.625));  // 18.19
    return 0;
}