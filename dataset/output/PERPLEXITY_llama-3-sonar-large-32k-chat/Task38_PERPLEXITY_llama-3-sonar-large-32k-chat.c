#include <stdio.h>

int main() {
    printf("Content-type: text/html\r
\r
");
    printf("<html><body>");
    if (getenv("REQUEST_METHOD") && strcmp(getenv("REQUEST_METHOD"), "POST") == 0) {
        char name[1024];
        scanf("%s", name);
        printf("<h1>Hello, %s!</h1>", name);
    } else {
        printf("<form action=\"\" method=\"post\">");
        printf("    <input type=\"text\" name=\"name\" placeholder=\"Enter your name\">");
        printf("    <input type=\"submit\" value=\"Submit\">");
        printf("</form>");
    }
    printf("</body></html>");
    return 0;
}