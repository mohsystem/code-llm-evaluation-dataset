// C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* expandedForm(int num) {
    char* result = malloc(sizeof(char) * 50);
    int digits[] = {10000, 1000, 100, 10, 1};
    int i = 0;
    for (; i < 5; i++) {
        if (num >= digits[i]) {
            int count = num / digits[i];
            sprintf(result + strlen(result), "%d", count * digits[i]);
            num -= count * digits[i];
            if (num > 0) {
                strcat(result, " + ");
            }
        }
    }
    return result;
}