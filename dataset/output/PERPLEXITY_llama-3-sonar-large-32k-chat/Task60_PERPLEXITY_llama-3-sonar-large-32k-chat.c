#include <stdio.h>
#include <string.h>

char* expandedForm(int num) {
    static char str[100];
    sprintf(str, "%d", num);
    char result[100] = "";
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] != '0') {
            strncat(result, &str[i], 1);
            for (int j = i + 1; j < len; j++) {
                strncat(result, "0", 1);
            }
            if (i < len - 1) {
                strncat(result, " + ", 3);
            }
        }
    }
    return str;
}