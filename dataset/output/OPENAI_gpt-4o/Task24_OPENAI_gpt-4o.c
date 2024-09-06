#include <stdio.h>
#include <string.h>
#include <ctype.h>

int validatePin(const char* pin) {
    size_t length = strlen(pin);
    if (length == 4 || length == 6) {
        for (size_t i = 0; i < length; ++i) {
            if (!isdigit(pin[i])) {
                return 0;
            }
        }
        return 1;
    }
    return 0;
}

int main() {
    printf("%d\n", validatePin("1234"));  // true (1)
    printf("%d\n", validatePin("12345")); // false (0)
    printf("%d\n", validatePin("a234"));  // false (0)
    return 0;
}