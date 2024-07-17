#include <ctype.h>
#include <string.h>
#include <stdbool.h>

bool getXO (const char *str) {
    int x = 0;
    int o = 0;
    for(int i = 0; i < strlen(str); i++) {
        char c = tolower(str[i]);
        if(c == 'x')
            x++;
        else if(c == 'o')
            o++;
    }
    return x == o;
}