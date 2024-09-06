#include <stdio.h>
#include <math.h>
#include <string.h>

int isNarcissistic(int number) {
    char numStr[12];
    sprintf(numStr, "%d", number);
    int power = strlen(numStr);
    int sum = 0;
    
    for (int i = 0; i < power; i++) {
        int digit = numStr[i] - '0';
        sum += pow(digit, power);
    }
    
    return sum == number;
}

int main() {
    printf("%d\n", isNarcissistic(153));  // 1 (true)
    printf("%d\n", isNarcissistic(1652));  // 0 (false)
    return 0;
}