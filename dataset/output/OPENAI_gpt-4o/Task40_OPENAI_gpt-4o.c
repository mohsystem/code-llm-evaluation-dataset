#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcgi_stdio.h>

#define CSRF_TOKEN "aCSRFtoken"

void generate_html(char *csrf_token) {
    printf("Content-type: text/html\n\n");
    printf("<form method='POST' action='/cgi-bin/settings.cgi'>");
    printf("<input type='hidden' name='_csrf_token' value='%s'/>", csrf_token);
    printf("<input type='text' name='username' placeholder='Username'/>");
    printf("<button type='submit'>Save</button>");
    printf("</form>");
}

void handle_request() {
    char *method = getenv("REQUEST_METHOD");
    if (method && strcmp(method, "POST") == 0) {
        char *content_type = getenv("CONTENT_TYPE");
        if (content_type && strcmp(content_type, "application/x-www-form-urlencoded") == 0) {
            char *post_data = NULL;
            size_t len = 0;
            FILE *post_stream = fdopen(0, "r");
            getline(&post_data, &len, post_stream);

            if (post_data && strstr(post_data, "_csrf_token=" CSRF_TOKEN)) {
                // Save settings logic here
                printf("Content-type: text/plain\n\n");
                printf("Settings updated!");
            } else {
                printf("Content-type: text/plain\n\n");
                printf("CSRF token is missing or incorrect");
            }
            free(post_data);
        }
    } else {
        generate_html(CSRF_TOKEN);
    }
}

int main(void) {
    while (FCGI_Accept() >= 0) {
        handle_request();
    }
    return 0;
}