#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
double cubeDiagonal(double volume) {
  return round(sqrt(3) * pow(volume, 1.0/3) * 100.0) / 100.0;
}
int main() {
  return 0;
}