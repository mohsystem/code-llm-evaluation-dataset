#include <stdio.h>
#include <string.h>

int largestProduct(const char* inputStr, int span) {
    int maxProduct = 0;
    for (int i = 0; i <= strlen(inputStr) - span; i++) {
        int product = 1;
        for (int j = 0; j < span; j++) {
            product *= inputStr[i + j] - '0';
        }
        if (product > maxProduct) {
            maxProduct = product;
        }
    }
    return maxProduct;
}

int main() {
    const char* inputStr = "63915";
    int span = 3;
    printf("%d\n", largestProduct(inputStr, span));
    return 0;
}