// C code
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool validatePin(const char* pin) {
    int len = strlen(pin);
    if (len != 4 && len != 6) return false;
    for (int i = 0; i < len; i++) {
        if (!isdigit(pin[i])) return false;
    }
    return true;
}

int main() {
    printf("%d
", validatePin("1234"));   // 1 (true)
    printf("%d
", validatePin("12345"));  // 0 (false)
    printf("%d
", validatePin("a234"));   // 0 (false)
    return 0;
}