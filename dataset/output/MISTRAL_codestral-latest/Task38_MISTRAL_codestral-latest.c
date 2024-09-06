// C CGI web application
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char* data = getenv("QUERY_STRING");
    if (data != NULL) {
        char* userInput = strstr(data, "user_input=");
        if (userInput != NULL) {
            userInput += strlen("user_input=");
            printf("Content-type: text/html\n\n");
            printf("<html><body>");
            printf("<h1>Your input: %s</h1>", userInput);
            printf("</body></html>");
        }
    }
    return 0;
}