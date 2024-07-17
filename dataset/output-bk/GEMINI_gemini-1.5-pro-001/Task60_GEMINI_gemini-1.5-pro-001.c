#include <stdio.h>
#include <math.h>

char *expandedForm(int num) {
    int len = 0;
    int temp = num;
    while (temp > 0) {
        len++;
        temp /= 10;
    }

    char *str = malloc(len * 5 * sizeof(char)); // Allocate enough memory
    str[0] = '\0'; // Initialize as empty string

    for (int i = 0; i < len; i++) {
        int digit = (int)(num / pow(10, len - i - 1)) % 10;
        if (digit != 0) {
            char part[20];
            sprintf(part, "%d", (int)(digit * pow(10, len - i - 1)));
            strcat(str, part);
            if (i != len - 1) {
                strcat(str, " + ");
            }
        }
    }
    return str;
}

int main() {
    printf("%s
", expandedForm(12));
    printf("%s
", expandedForm(42));
    printf("%s
", expandedForm(70304));
    return 0;
}