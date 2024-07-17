#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int maxProduct(char* input, int span) {
    int maxProd = 0;
    for (int i = 0; i <= strlen(input) - span; i++) {
        int prod = 1;
        for (int j = i; j < i + span; j++) {
            prod *= input[j] - '0';
        }
        if (prod > maxProd) {
            maxProd = prod;
        }
    }
    return maxProd;
}