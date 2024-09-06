// C (using CGI and HTML templates)
#include <stdio.h>
#include <string.h>

int main() {
    char csrfToken[] = "random_token_here";
    char method[10];
    if (getenv("REQUEST_METHOD") != NULL) {
        strcpy(method, getenv("REQUEST_METHOD"));
    }
    if (strcmp(method, "POST") == 0) {
        char csrfTokenForm[100];
        if (getenv("csrf_token") != NULL) {
            strcpy(csrfTokenForm, getenv("csrf_token"));
        }
        if (strcmp(csrfToken, csrfTokenForm) == 0) {
            // Update user settings here
            printf("Settings updated successfully");
        } else {
            printf("CSRF token is invalid");
        }
    } else {
        printf("Content-type:text/html\r\n\r\n");
        printf("<form action=\"\" method=\"post\">");
        printf("<input type=\"hidden\" name=\"csrf_token\" value=\"%s\">", csrfToken);
        printf("<label>Username:</label>");
        printf("<input type=\"text\" name=\"username\"><br><br>");
        printf("<label>Email:</label>");
        printf("<input type=\"email\" name=\"email\"><br><br>");
        printf("<input type=\"submit\" value=\"Update Settings\">");
        printf("</form>");
    }
    return 0;
}