
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool validate_pin(const char *pin) {
    int len = strlen(pin);
    if (len != 4 && len != 6) return false;
    for (int i = 0; i < len; i++) {
        if (!isdigit(pin[i])) return false;
    }
    return true;
}
