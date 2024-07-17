#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <uuid/uuid.h>

int main() {
    uuid_t uuid;
    char token[37];
    uuid_generate_random(uuid);
    uuid_unparse(uuid, token);
    printf("Content-type: text/html\r
\r
");
    printf("<form action='' method='post'>");
    printf("<input type='hidden' name='_csrf_token' value='%s'>", token);
    printf("<input type='submit' value='Submit'>");
    printf("</form>");

    char method[10];
    scanf("%9s", method);
    if (strcmp(method, "POST") == 0) {
        char postedToken[37];
        scanf("%36s", postedToken);
        if (strcmp(postedToken, token) != 0) {
            printf("Status: 403 Forbidden\r
\r
");
            printf("CSRF token missing or invalid");
        } else {
            printf("Form submitted successfully");
        }
    }
    return 0;
}