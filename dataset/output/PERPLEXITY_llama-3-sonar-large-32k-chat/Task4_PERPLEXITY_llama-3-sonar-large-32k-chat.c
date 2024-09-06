#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

bool isIsogram(const char* str) {
    int count[256] = {0};
    for (; *str; str++) {
        if (++count[tolower(*str)] > 1) {
            return false;
        }
    }
    return true;
}

int main() {
    printf("%d\n", isIsogram("Dermatoglyphics"));  // 1
    printf("%d\n", isIsogram("aba"));  // 0
    printf("%d\n", isIsogram("moOse"));  // 0
    return 0;
}