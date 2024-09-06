// C code using CGI and libuuid
#include <stdio.h>
#include <stdlib.h>
#include <uuid/uuid.h>

int main() {
    char method[10];
    if (scanf("%9s", method) != 1) {
        fprintf(stderr, "Error reading request method\n");
        return 1;
    }

    if (strcmp(method, "GET") == 0) {
        uuid_t uuid;
        uuid_generate_random(uuid);
        char uuid_str[37];
        uuid_unparse(uuid, uuid_str);
        printf("Content-Type: text/html\n\n");
        printf("<form action=\"\" method=\"post\"><input type=\"hidden\" name=\"_csrf_token\" value=\"%s\"><input type=\"submit\" value=\"Submit\"></form>", uuid_str);
    } else if (strcmp(method, "POST") == 0) {
        char token[37];
        if (scanf("%36s", token) != 1) {
            fprintf(stderr, "Error reading CSRF token\n");
            return 1;
        }
        char cookie[37];
        if (scanf("%36s", cookie) != 1) {
            fprintf(stderr, "Error reading CSRF cookie\n");
            return 1;
        }
        if (strcmp(token, cookie) == 0) {
            printf("Content-Type: text/html\n\nForm submitted successfully");
        } else {
            printf("Status: 403 Forbidden\n\nCSRF token missing or invalid");
        }
    }
    return 0;
}