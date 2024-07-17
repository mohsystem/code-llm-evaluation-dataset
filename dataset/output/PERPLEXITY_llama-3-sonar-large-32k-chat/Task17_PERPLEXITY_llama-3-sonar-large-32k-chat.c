#include <stdio.h>
#include <string.h>
#include <ctype.h>

char* toJadenCase(char* phrase) {
    if (phrase == NULL || phrase[0] == '\0') return NULL;
    char* p = phrase;
    while (*p != '\0') {
        if (p == phrase || *(p-1) == ' ') {
            *p = toupper((unsigned char)*p);
        } else {
            *p = tolower((unsigned char)*p);
        }
        p++;
    }
    return phrase;
}

int main() {
    char phrase[] = "How can mirrors be real if our eyes aren't real";
    char* jadenCase = toJadenCase(phrase);
    printf("%s
", jadenCase);
    return 0;
}