// C does not have built-in support for regular expressions. You can use the POSIX regex library, but it's not part of the standard library.
// You can use the following code, but it requires the POSIX regex library to be installed and linked:
#include <regex.h>
#include <stdio.h>

int main() {
    regex_t pattern;
    regcomp(&pattern, "^[a-zA-Z0-9_]{3,16}$", 0);
    char user_input[256];
    printf("Enter a username: ");
    fgets(user_input, 256, stdin);
    user_input[strcspn(user_input, "\n")] = 0; // remove newline character
    int status = regexec(&pattern, user_input, 0, NULL, 0);
    if (status == 0) {
        printf("Valid username\n");
    } else {
        printf("Invalid username\n");
    }
    regfree(&pattern);
    return 0;
}