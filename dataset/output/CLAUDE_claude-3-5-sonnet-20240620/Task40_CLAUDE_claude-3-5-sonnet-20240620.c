
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_TOKEN_LENGTH 33
#define MAX_INPUT_LENGTH 256

char csrf_token[MAX_TOKEN_LENGTH];

void generate_csrf_token() {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    int charset_length = strlen(charset);
    
    srand(time(NULL));
    for (int i = 0; i < MAX_TOKEN_LENGTH - 1; i++) {
        csrf_token[i] = charset[rand() % charset_length];
    }
    csrf_token[MAX_TOKEN_LENGTH - 1] = \'\\0\';
}

void render_form() {
    printf("Content-Type: text/html\
\
");
    printf("<html><body>");
    printf("<h1>User Settings</h1>");
    printf("<form method=\'post\' action=\'settings.cgi\'>");
    printf("<input type=\'hidden\' name=\'csrf_token\' value=\'%s\'>", csrf_token);
    printf("Name: <input type=\'text\' name=\'name\'><br>");
    printf("Email: <input type=\'email\' name=\'email\'><br>");
    printf("<input type=\'submit\' value=\'Update\'>");
    printf("</form>");
    printf("</body></html>");
}

void update_settings(const char* name, const char* email) {
    printf("Content-Type: text/html\
\
");
    printf("<html><body>");
    printf("<h1>Settings Updated</h1>");
    printf("<p>Name: %s</p>", name);
    printf("<p>Email: %s</p>", email);
    printf("</body></html>");
}

char* get_post_data() {
    char* data = NULL;
    int content_length = 0;
    char* content_length_str = getenv("CONTENT_LENGTH");
    
    if (content_length_str != NULL) {
        content_length = atoi(content_length_str);
        if (content_length > 0) {
            data = malloc(content_length + 1);
            fgets(data, content_length + 1, stdin);
        }
    }
    
    return data;
}

void parse_post_data(char* data, char* name, char* email, char* token) {
    char* pair = strtok(data, "&");
    while (pair != NULL) {
        char* key = strtok(pair, "=");
        char* value = strtok(NULL, "=");
        
        if (strcmp(key, "name") == 0) {
            strcpy(name, value);
        } else if (strcmp(key, "email") == 0) {
            strcpy(email, value);
        } else if (strcmp(key, "csrf_token") == 0) {
            strcpy(token, value);
        }
        
        pair = strtok(NULL, "&");
    }
}

int main() {
    char* request_method = getenv("REQUEST_METHOD");
    
    if (strcmp(request_method, "GET") == 0) {
        generate_csrf_token();
        render_form();
    } else if (strcmp(request_method, "POST") == 0) {
        char* post_data = get_post_data();
        if (post_data != NULL) {
            char name[MAX_INPUT_LENGTH] = "";
            char email[MAX_INPUT_LENGTH] = "";
            char token[MAX_TOKEN_LENGTH] = "";
            
            parse_post_data(post_data, name, email, token);
            
            if (strcmp(token, csrf_token) == 0) {
                update_settings(name, email);
            } else {
                printf("Content-Type: text/html\
\
");
                printf("<html><body>");
                printf("<h1>Error: Invalid CSRF Token</h1>");
                printf("</body></html>");
            }
            
            free(post_data);
        }
    }
    
    return 0;
}
