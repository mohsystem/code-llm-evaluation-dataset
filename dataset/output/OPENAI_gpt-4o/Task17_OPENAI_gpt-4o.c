#include <stdio.h>
#include <string.h>
#include <ctype.h>

void toJadenCase(char* phrase) {
    if (phrase == NULL || strlen(phrase) == 0) {
        return;
    }
    int len = strlen(phrase);
    int capitalizeNext = 1;
    for (int i = 0; i < len; i++) {
        if (phrase[i] == ' ') {
            capitalizeNext = 1;
        } else if (capitalizeNext) {
            phrase[i] = toupper(phrase[i]);
            capitalizeNext = 0;
        } else {
            phrase[i] = tolower(phrase[i]);
        }
    }
}

int main() {
    char phrase[] = "How can mirrors be real if our eyes aren't real";
    toJadenCase(phrase);
    printf("%s\n", phrase);
    return 0;
}