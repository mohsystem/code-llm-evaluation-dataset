
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* expanded_form(int num) {
    char numStr[20];
    sprintf(numStr, "%d", num);
    int len = strlen(numStr);
    
    char* result = malloc(100 * sizeof(char));
    result[0] = '\\0';
    
    for (int i = 0; i < len; i++) {
        if (numStr[i] != '0') {
            if (strlen(result) > 0) {
                strcat(result, " + ");
            }
            char part[20];
            sprintf(part, "%c", numStr[i]);
            strcat(result, part);
            for (int j = 0; j < len - i - 1; j++) {
                strcat(result, "0");
            }
        }
    }
    
    return result;
}

int main() {
    printf("%s\\n", expanded_form(12));    // Output: 10 + 2
    printf("%s\\n", expanded_form(42));    // Output: 40 + 2
    printf("%s\\n", expanded_form(70304)); // Output: 70000 + 300 + 4
    return 0;
}
