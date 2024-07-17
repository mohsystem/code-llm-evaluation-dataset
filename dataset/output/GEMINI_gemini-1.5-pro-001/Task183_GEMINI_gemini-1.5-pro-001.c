#include <stdio.h>
#include <string.h>

int largestProduct(const char *digits, int span) {
    if (span < 1 || span > strlen(digits)) {
        return -1;
    }
    int maxProduct = 0;
    for (int i = 0; i <= strlen(digits) - span; i++) {
        int product = 1;
        for (int j = i; j < i + span; j++) {
            product *= (digits[j] - '0');
        }
        if (product > maxProduct) {
            maxProduct = product;
        }
    }
    return maxProduct;
}

int main() {
    // Example usage:
    char digits[] = "63915";
    int span = 3;
    int result = largestProduct(digits, span);
    printf("Largest product: %d
", result);
    return 0;
}