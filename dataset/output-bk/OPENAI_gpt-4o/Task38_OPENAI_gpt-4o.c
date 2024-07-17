#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcgi_stdio.h>

int main() {
    while(FCGI_Accept() >= 0) {
        char *contentLength = getenv("CONTENT_LENGTH");
        int len = contentLength ? atoi(contentLength) : 0;
        
        printf("Content-type: text/html\r
\r
");
        printf("<html><body>");
        
        if(len > 0) {
            char *input = malloc(len + 1);
            fread(input, 1, len, stdin);
            input[len] = '\0';
            char *userInput = strstr(input, "userInput=") + 10;
            printf("<h1>You entered: %s</h1>", userInput);
            free(input);
        }
        
        printf("</body></html>");
    }
    return 0;
}