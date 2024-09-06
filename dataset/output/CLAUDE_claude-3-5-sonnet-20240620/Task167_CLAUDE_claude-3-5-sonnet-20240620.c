
#include <math.h>

double cubeDiagonal(double volume) {
    double side = cbrt(volume);
    double diagonal = sqrt(3) * side;
    return round(diagonal * 100.0) / 100.0;
}
