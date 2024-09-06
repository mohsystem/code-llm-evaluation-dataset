#include <stdio.h>
#include <string.h>

char* expandedForm(int num) {
    char numStr[12];
    sprintf(numStr, "%d", num);
    int len = strlen(numStr);
    char* expanded = (char*)malloc(sizeof(char) * (len * 3)); // Allocate memory for the expanded form
    int index = 0;
    for (int i = 0; i < len; i++) {
        char digit = numStr[i];
        if (digit != '0') {
            if (index > 0) {
                expanded[index++] = ' ';
                expanded[index++] = '+';
                expanded[index++] = ' ';
            }
            expanded[index++] = digit;
            for (int j = 0; j < len - i - 1; j++) {
                expanded[index++] = '0';
            }
        }
    }
    expanded[index] = '\0'; // Null-terminate the string
    return expanded;
}