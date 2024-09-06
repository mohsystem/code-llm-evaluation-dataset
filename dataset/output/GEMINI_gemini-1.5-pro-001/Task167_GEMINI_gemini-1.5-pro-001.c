#include <stdio.h>
#include <math.h>

double cubeDiagonal(double volume) {
  return round(sqrt(3) * pow(volume, 1.0/3) * 100.0) / 100.0;
}

int main() {
  // you can test your code here
  return 0;
}