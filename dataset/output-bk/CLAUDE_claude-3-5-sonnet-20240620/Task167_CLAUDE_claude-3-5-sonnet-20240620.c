
#include <stdio.h>
#include <math.h>

double cubeDiagonal(double volume) {
    double side = cbrt(volume);
    double diagonal = sqrt(3) * side;
    return round(diagonal * 100.0) / 100.0;
}

int main() {
    printf("%.2f\
", cubeDiagonal(8));
    printf("%.2f\
", cubeDiagonal(343));
    printf("%.2f\
", cubeDiagonal(1157.625));
    return 0;
}
