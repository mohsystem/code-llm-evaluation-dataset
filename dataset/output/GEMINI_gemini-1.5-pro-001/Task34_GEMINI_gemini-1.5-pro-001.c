#include <math.h>
#include <stdbool.h>
#include <stdio.h>

bool narcissistic(int value) {
  int originalValue = value;
  int numDigits = 0;
  while (value > 0) {
    value /= 10;
    numDigits++;
  }

  value = originalValue;
  int total = 0;
  while (value > 0) {
    int digit = value % 10;
    total += pow(digit, numDigits);
    value /= 10;
  }

  return total == originalValue;
}