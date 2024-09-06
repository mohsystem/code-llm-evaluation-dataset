#include <stdio.h>
#include <string.h>

char* expandedForm(int num) {
    char numStr[20];
    sprintf(numStr, "%d", num);
    char result[100] = "";
    for (int i = 0; i < strlen(numStr); i++) {
        if (numStr[i] != '0') {
            char temp[20] = "";
            temp[0] = numStr[i];
            for (int j = 0; j < strlen(numStr) - i - 1; j++) {
                strcat(temp, "0");
            }
            strcat(result, temp);
            strcat(result, " + ");
        }
    }
    result[strlen(result) - 3] = '\0';
    return strdup(result);
}