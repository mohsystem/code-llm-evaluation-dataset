#include <ctype.h>
#include <string.h>

#define MAX_CHAR 256

int isIsogram(char *str) {
    int count[MAX_CHAR] = {0};
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        str[i] = tolower(str[i]);
        count[str[i]]++;
        if (count[str[i]] > 1) {
            return 0;
        }
    }
    return 1;
}