// C
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void toJadenCase(char *str) {
    int i;
    for (i = 0; str[i]; i++) {
        if (i == 0 || str[i - 1] == ' ') {
            str[i] = toupper(str[i]);
        }
    }
}

int main() {
    char str[] = "How can mirrors be real if our eyes aren't real";
    toJadenCase(str);
    printf("%s", str);
    return 0;
}