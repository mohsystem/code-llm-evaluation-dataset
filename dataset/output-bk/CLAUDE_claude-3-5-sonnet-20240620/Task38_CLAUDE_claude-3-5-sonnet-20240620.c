
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 1000

void print_html_header() {
    printf("Content-Type: text/html\
\
");
    printf("<html><head><title>Form Results</title></head><body>");
}

void print_html_footer() {
    printf("</body></html>");
}

int main() {
    char *data;
    char name[100] = "", email[100] = "";

    print_html_header();

    data = getenv("REQUEST_METHOD");
    if (data && strcmp(data, "POST") == 0) {
        int content_length = atoi(getenv("CONTENT_LENGTH"));
        char input[MAX_INPUT];
        fgets(input, content_length + 1, stdin);

        char *token = strtok(input, "&");
        while (token != NULL) {
            if (strncmp(token, "name=", 5) == 0) {
                strcpy(name, token + 5);
            } else if (strncmp(token, "email=", 6) == 0) {
                strcpy(email, token + 6);
            }
            token = strtok(NULL, "&");
        }

        printf("<h2>Submitted Information:</h2>");
        printf("<p>Name: %s</p>", name);
        printf("<p>Email: %s</p>", email);
    } else {
        printf("<h2>User Input Form</h2>");
        printf("<form method=\'post\'>");
        printf("Name: <input type=\'text\' name=\'name\'><br>");
        printf("Email: <input type=\'text\' name=\'email\'><br>");
        printf("<input type=\'submit\' value=\'Submit\'>");
        printf("</form>");
    }

    print_html_footer();
    return 0;
}
