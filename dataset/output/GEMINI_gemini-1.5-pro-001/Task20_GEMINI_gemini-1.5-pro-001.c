#include <math.h>

long long digPow(int n, int p) {
  int temp = n;
  int count = 0;
  
  while (temp != 0) {
    temp /= 10;
    ++count;
  }

  long long sum = 0;
  temp = n;

  for (int i = count - 1; i >= 0; --i) {
    int digit = temp / (int)pow(10, i);
    sum += (long long)pow(digit, p + count - i - 1);
    temp %= (int)pow(10, i);
  }

  return (sum % n == 0) ? sum / n : -1;
}