
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* expandedForm(int num) {
    char numStr[20];
    sprintf(numStr, "%d", num);
    int len = strlen(numStr);
    char* result = malloc(len * 10);
    result[0] = \'\\0\';

    for (int i = 0; i < len; i++) {
        if (numStr[i] != \'0\') {
            if (strlen(result) > 0) {
                strcat(result, " + ");
            }
            char temp[20];
            sprintf(temp, "%c", numStr[i]);
            strcat(result, temp);
            for (int j = 0; j < len - i - 1; j++) {
                strcat(result, "0");
            }
        }
    }
    return result;
}

int main() {
    printf("%s\
", expandedForm(12));
    printf("%s\
", expandedForm(42));
    printf("%s\
", expandedForm(70304));
    return 0;
}
