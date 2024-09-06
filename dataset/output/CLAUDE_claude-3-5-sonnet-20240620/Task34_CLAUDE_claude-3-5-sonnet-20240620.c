
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

bool narcissistic(int num) {
    char numStr[20];
    sprintf(numStr, "%d", num);
    int power = strlen(numStr);
    int sum = 0;
    
    for (int i = 0; i < power; i++) {
        sum += pow(numStr[i] - '0', power);
    }
    
    return sum == num;
}

int main() {
    printf("%s\\n", narcissistic(153) ? "true" : "false");  // true
    printf("%s\\n", narcissistic(1652) ? "true" : "false");  // false
    return 0;
}
