#include <math.h>
#include <stdlib.h>

int dig_pow(int n, int p) {
    char *s = malloc(sizeof(char) * 10);
    sprintf(s, "%d", n);
    int sum = 0;
    for (int i = 0; s[i]; i++) {
        sum += pow(s[i] - '0', p + i);
    }
    free(s);
    return sum % n == 0 ? sum / n : -1;
}