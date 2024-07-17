#include <cmath>
int getSum(int a, int b) {
  return (a == b) ? a : (a + b) * (std::abs(a - b) + 1) / 2; 
}