
#include <stdio.h>
#include <string.h>

long long largestSeriesProduct(const char* inputSequence, int span) {
    int length = strlen(inputSequence);
    if (span > length || span <= 0) {
        return -1; // Invalid input
    }
    
    long long maxProduct = 0;
    
    for (int i = 0; i <= length - span; ++i) {
        long long product = 1;
        for (int j = i; j < i + span; ++j) {
            product *= inputSequence[j] - '0';
        }
        if (product > maxProduct) {
            maxProduct = product;
        }
    }
    
    return maxProduct;
}

int main() {
    const char* inputSequence = "63915";
    int span = 3;
    long long result = largestSeriesProduct(inputSequence, span);
    printf("The largest product of %d adjacent digits in %s is: %lld\\n", span, inputSequence, result);
    return 0;
}
