#include <stdio.h>
#include <string.h>

int largestProduct(const char* digits, int span) {
    if (span == 0) {
        return 1;
    }
    int maxProduct = 0;
    int length = strlen(digits);
    for (int i = 0; i <= length - span; i++) {
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
    const char* digits = "63915";
    int span = 3;
    printf("%d
", largestProduct(digits, span));
    return 0;
}