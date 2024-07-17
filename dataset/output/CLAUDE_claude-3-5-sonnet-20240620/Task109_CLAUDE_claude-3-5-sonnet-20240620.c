
#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <string.h>

#define MAX_INPUT 100

int validate_input(const char* input, const char* regex_pattern) {
    regex_t regex;
    int reti;
    
    reti = regcomp(&regex, regex_pattern, REG_EXTENDED);
    if (reti) {
        fprintf(stderr, "Could not compile regex\
");
        exit(1);
    }
    
    reti = regexec(&regex, input, 0, NULL, 0);
    regfree(&regex);
    
    return reti == 0;
}

int main() {
    char email[MAX_INPUT];
    char phone[MAX_INPUT];
    
    printf("Enter an email address: ");
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\
")] = 0;
    
    if (validate_input(email, "^[A-Za-z0-9+_.-]+@[A-Za-z0-9.-]+$")) {
        printf("Valid email address\
");
    } else {
        printf("Invalid email address\
");
    }
    
    printf("Enter a phone number (XXX-XXX-XXXX): ");
    fgets(phone, sizeof(phone), stdin);
    phone[strcspn(phone, "\
")] = 0;
    
    if (validate_input(phone, "^[0-9]{3}-[0-9]{3}-[0-9]{4}$")) {
        printf("Valid phone number\
");
    } else {
        printf("Invalid phone number\
");
    }
    
    return 0;
}
