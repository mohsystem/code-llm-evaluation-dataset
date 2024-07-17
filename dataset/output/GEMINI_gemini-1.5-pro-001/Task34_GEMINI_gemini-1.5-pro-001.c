#include <stdbool.h>
#include <math.h>

bool is_narcissistic(int num) {
  if (num < 0) {
    return false;
  }
  int originalNum = num;
  int sum = 0;
  int digits = floor(log10(abs(num))) + 1;
  while (num > 0) {
    int digit = num % 10;
    sum += pow(digit, digits);
    num /= 10;
  }
  return sum == originalNum;
}