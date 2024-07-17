#include <stdio.h>
#include <string.h>

void expandedForm(int num) {
    char result[100] = "";
    char str[20];
    sprintf(str, "%d", num);
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        if (str[i] != '0') {
            char part[20];
            sprintf(part, "%c", str[i]);
            for (int j = i + 1; j < len; j++) {
                strcat(part, "0");
            }

            strcat(result, part);
            if (i < len - 1) {
                strcat(result, " + ");
            }
        }
    }

    if (result[strlen(result) - 1] == ' ') {
        result[strlen(result) - 3] = '\0';
    }
    printf("%s
", result);
}

int main() {
    expandedForm(12);   // Should return "10 + 2"
    expandedForm(42);   // Should return "40 + 2"
    expandedForm(70304); // Should return "70000 + 300 + 4"
    return 0;
}