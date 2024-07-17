#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 1024

void print_html(const char *userInput) {
    printf("Content-Type: text/html

");
    printf("<html><body>
");
    printf("<h1>User Input:</h1>
");
    printf("<p>%s</p>
", userInput);
    printf("</body></html>
");
}

int main(void) {
    char *data = getenv("QUERY_STRING");
    char input[MAX_INPUT] = {0};

    if (data) {
        strncpy(input, data, MAX_INPUT-1);
    }

    // Assuming input is in the format "userInput=value"
    char *userInput = strchr(input, '=');
    if (userInput) {
        userInput++;
    } else {
        userInput = "";
    }

    print_html(userInput);
    return 0;
}