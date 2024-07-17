
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 1000

int main() {
    char *method = getenv("REQUEST_METHOD");
    char input[MAX_INPUT] = {0};

    printf("Content-Type: text/html\
\
");
    printf("<html><body>");

    if (strcmp(method, "POST") == 0) {
        int content_length = atoi(getenv("CONTENT_LENGTH"));
        fgets(input, content_length + 1, stdin);
        char *user_input = strchr(input, \'=\') + 1;
        
        printf("<h2>User Input:</h2>");
        printf("<p>%s</p>", user_input);
    } else {
        printf("<h2>Enter your input:</h2>");
        printf("<form method=\'post\'>");
        printf("<input type=\'text\' name=\'userInput\'>");
        printf("<input type=\'submit\' value=\'Submit\'>");
        printf("</form>");
    }

    printf("</body></html>");
    return 0;
}
