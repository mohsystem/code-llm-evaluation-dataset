#include <stdio.h>
#include <regex.h>

int is_valid_email(const char *email);

int main() {
    char email[256];
    printf("Enter an email address:
");
    scanf("%s", email);

    if (is_valid_email(email)) {
        printf("Valid email address.
");
    } else {
        printf("Invalid email address.
");
    }
    return 0;
}

int is_valid_email(const char *email) {
    regex_t regex;
    const char *email_regex = "^[a-zA-Z0-9_+&*-]+(?:\\.[a-zA-Z0-9_+&*-]+)*@(?:[a-zA-Z0-9-]+\\.)+[a-zA-Z]{2,7}$";
    int result;

    regcomp(&regex, email_regex, REG_EXTENDED);
    result = regexec(&regex, email, 0, NULL, 0);
    regfree(&regex);

    return result == 0;
}