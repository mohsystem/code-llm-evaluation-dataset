
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("Select a destination:\\n");
    printf("1. Google\\n");
    printf("2. YouTube\\n");
    printf("3. Wikipedia\\n");

    char choice[2];
    printf("Enter your choice (1-3): ");
    fgets(choice, sizeof(choice), stdin);

    char* url;
    if (strcmp(choice, "1\\n") == 0) {
        url = "https://www.google.com";
    } else if (strcmp(choice, "2\\n") == 0) {
        url = "https://www.youtube.com";
    } else if (strcmp(choice, "3\\n") == 0) {
        url = "https://www.wikipedia.org";
    } else {
        printf("Invalid choice. Please try again.\\n");
        return 1;
    }

    #ifdef _WIN32
        char command[256] = "start ";
    #elif __APPLE__
        char command[256] = "open ";
    #else
        char command[256] = "xdg-open ";
    #endif

    strcat(command, url);
    system(command);

    return 0;
}
