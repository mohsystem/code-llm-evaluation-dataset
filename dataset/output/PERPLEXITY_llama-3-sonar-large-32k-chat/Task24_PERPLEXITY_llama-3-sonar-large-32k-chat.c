#include <stdio.h>
#include <string.h>
#include <ctype.h>

int validatePin(char *pin) {
    if (strlen(pin) == 4 || strlen(pin) == 6) {
        for (int i = 0; i < strlen(pin); i++) {
            if (!isdigit(pin[i])) {
                return 0;
            }
        }
        return 1;
    }
    return 0;
}

int main() {
    printf("%d
", validatePin("1234")); // 1
    printf("%d
", validatePin("12345")); // 0
    printf("%d
", validatePin("a234")); // 0
    return 0;
}