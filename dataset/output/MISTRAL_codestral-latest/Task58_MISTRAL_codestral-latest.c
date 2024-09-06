#include <ctype.h>
#include <string.h>

int XO(const char *str) {
    int x = 0, o = 0;
    for(int i = 0; str[i]; i++) {
        char c = tolower(str[i]);
        if(c == 'x') x++;
        else if(c == 'o') o++;
    }
    return x == o;
}