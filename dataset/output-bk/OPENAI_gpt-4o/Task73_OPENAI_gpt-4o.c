#include <stdio.h>
#include <string.h>

void runCPasswordCheck(const char* password) {
    if (strcmp(password, "admin123") == 0) {
        printf("C: Password is valid.
");
    } else {
        printf("C: Password is invalid.
");
    }
}