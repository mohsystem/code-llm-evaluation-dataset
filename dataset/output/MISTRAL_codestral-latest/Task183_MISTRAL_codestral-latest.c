#include <string.h>
#include <stdlib.h>

int maxProduct(char *input, int span) {
    int maxProd = 0;
    for (int i = 0; i <= strlen(input) - span; i++) {
        char series[span + 1];
        strncpy(series, input + i, span);
        series[span] = '\0';
        int product = 1;
        for (int j = 0; j < span; j++) {
            product *= series[j] - '0';
        }
        if (product > maxProd) {
            maxProd = product;
        }
    }
    return maxProd;
}