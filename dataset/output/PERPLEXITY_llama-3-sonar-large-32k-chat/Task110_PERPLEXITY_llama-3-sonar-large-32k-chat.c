// C does not have built-in support for regular expressions, so we'll use a simple validation
#include <stdio.h>
#include <string.h>

int validateUrl(const char* url) {
    if (strstr(url, "http://") == url || strstr(url, "https://") == url || strstr(url, "ftp://") == url) {
        return 1;
    }
    return 0;
}

int main() {
    char url[256];
    printf("Enter a URL: ");
    fgets(url, 256, stdin);
    url[strcspn(url, "\n")] = 0; // remove newline character
    if (validateUrl(url)) {
        printf("URL is valid\n");
    } else {
        printf("URL is not valid\n");
    }
    return 0;
}