
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

bool XO(const char* str)
{
    int x_count = 0, o_count = 0;
    for (int i = 0; str[i]; i++) {
        char c = tolower(str[i]);
        if (c == 'x') x_count++;
        else if (c == 'o') o_count++;
    }
    return x_count == o_count;
}
