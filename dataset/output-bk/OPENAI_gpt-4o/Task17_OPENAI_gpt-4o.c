#include <stdio.h>
#include <ctype.h>
#include <string.h>

void toJadenCase(char *phrase, char *result) {
    if (phrase == NULL || strlen(phrase) == 0) {
        strcpy(result, "");
        return;
    }

    int len = strlen(phrase);
    int capitalize = 1;

    for (int i = 0; i < len; i++) {
        if (capitalize && isalpha(phrase[i])) {
            result[i] = toupper(phrase[i]);
            capitalize = 0;
        } else {
            result[i] = phrase[i];
        }

        if (phrase[i] == ' ') {
            capitalize = 1;
        }
    }
    result[len] = '\0';
}

int main() {
    // Add test cases here
    char result[100];
    toJadenCase("How can mirrors be real if our eyes aren't real", result);
    printf("%s
", result);

    toJadenCase("", result);
    printf("%s
", result);

    toJadenCase(NULL, result);
    printf("%s
", result); // No output for NULL input
    return 0;
}