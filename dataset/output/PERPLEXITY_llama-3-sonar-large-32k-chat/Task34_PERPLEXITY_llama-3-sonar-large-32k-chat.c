#include <math.h>
#include <string.h>

int narcissistic(int value) {
    int sum = 0;
    char strValue[20];
    sprintf(strValue, "%d", value);
    for (int i = 0; i < strlen(strValue); i++) {
        sum += pow(strValue[i] - '0', strlen(strValue));
    }
    return value == sum;
}