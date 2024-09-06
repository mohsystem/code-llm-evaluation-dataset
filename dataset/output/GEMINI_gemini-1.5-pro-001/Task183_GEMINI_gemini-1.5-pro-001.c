#include <stdio.h>
#include <string.h>

int largestProduct(const char *digits, int span) {
  int len = strlen(digits);
  if (len < span || span < 1) {
    return 0;
  }
  int maxProduct = 0;
  for (int i = 0; i <= len - span; i++) {
    int product = 1;
    for (int j = i; j < i + span; j++) {
      product *= digits[j] - '0';
    }
    if (product > maxProduct) {
      maxProduct = product;
    }
  }
  return maxProduct;
}

int main() {
  char digits[] = "63915";
  int span = 3;
  int result = largestProduct(digits, span);
  printf("%d\n", result);
  return 0;
}