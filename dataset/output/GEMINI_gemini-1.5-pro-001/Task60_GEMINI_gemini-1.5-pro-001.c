#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *expandedForm(int num) {
    char numStr[20]; 
    sprintf(numStr, "%d", num);
    int length = strlen(numStr);
    char *result = (char *)malloc(length * length * sizeof(char)); 
    result[0] = '\0'; 
    for (int i = 0; i < length; i++) {
        if (numStr[i] != '0') {
            if (strlen(result) > 0) {
                strcat(result, " + ");
            }
            strncat(result, &numStr[i], 1);
            for (int j = i + 1; j < length; j++) {
                strncat(result, "0", 1); 
            }
        }
    }
    return result;
}