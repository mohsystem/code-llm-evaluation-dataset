#include <stdio.h>
#include <regex.h>

int main() {
    char input[100];
    printf("Enter input: ");
    fgets(input, sizeof(input), stdin);

    // Regex pattern to validate input
    const char *regex = "^[a-zA-Z0-9]*$";
    regex_t regexCompiled;
    int reti = regcomp(&regexCompiled, regex, 0);
    if(reti) {
        printf("Could not compile regex
");
        return 1;
    }

    reti = regexec(&regexCompiled, input, 0, NULL, 0);
    if(!reti) {
        printf("Valid input
");
    } else if(reti == REG_NOMATCH) {
        printf("Invalid input
");
    } else {
        printf("Regex match failed
");
    }

    regfree(&regexCompiled);
    return 0;
}