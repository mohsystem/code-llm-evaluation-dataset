#include <ctype.h>
#include <string.h>

int validate_pin(const char *pin) {
    int len = strlen(pin);
    if (len != 4 && len != 6)
        return 0;
    for (int i = 0; i < len; i++)
        if (!isdigit(pin[i]))
            return 0;
    return 1;
}