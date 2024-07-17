#include <stdio.h>
#include <regex.h>

int main() {
    char input[100];
    regex_t regex;
    int reti;

    printf("Enter a string in C:
");
    fgets(input, 100, stdin);
    reti = regcomp(&regex, "^[a-zA-Z0-9]*$", 0);
    reti = regexec(&regex, input, 0, NULL, 0);
    if (!reti) {
        printf("Valid C Input
");
    } else {
        printf("Invalid C Input
");
    }
    regfree(&regex);
    return 0;
}