#include <stdio.h>
#include <string.h>

int findLargestProduct(const char* sequence, int span) {
    int maxProduct = 0;
    int length = strlen(sequence);
    
    for (int i = 0; i <= length - span; i++) {
        int product = 1;
        for (int j = 0; j < span; j++) {
            product *= sequence[i + j] - '0';
        }
        if (product > maxProduct) {
            maxProduct = product;
        }
    }
    return maxProduct;
}

int main() {
    const char* sequence = "63915";
    int span = 3;
    printf("%d\n", findLargestProduct(sequence, span));
    return 0;
}