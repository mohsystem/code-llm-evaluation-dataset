#include<stdio.h>
#include<math.h>

double cubeDiagonal(double volume) {
    double sideLength = cbrt(volume);
    double diagonalLength = round(sideLength * sqrt(3) * 100.0) / 100.0;
    return diagonalLength;
}