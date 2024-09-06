#include <stdio.h>
#include <string.h>

void expandedForm(int num, char *output) {
    char numStr[20];    
    sprintf(numStr, "%d", num);
    int len = strlen(numStr);
    char result[200] = "";
    
    for (int i = 0; i < len; i++) {
        if (numStr[i] != '0') {
            if (strlen(result) > 0) {
                strcat(result, " + ");
            }
            strncat(result, &numStr[i], 1);
            for (int j = i+1; j < len; j++) {
                strcat(result, "0");
            }
        }
    }
    strcpy(output, result);
}

int main() {
    char output[200];
    
    expandedForm(12, output);
    printf("%s\n", output); // Should return "10 + 2"
    
    expandedForm(42, output);
    printf("%s\n", output); // Should return "40 + 2"
    
    expandedForm(70304, output);
    printf("%s\n", output); // Should return "70000 + 300 + 4"
    
    return 0;
}