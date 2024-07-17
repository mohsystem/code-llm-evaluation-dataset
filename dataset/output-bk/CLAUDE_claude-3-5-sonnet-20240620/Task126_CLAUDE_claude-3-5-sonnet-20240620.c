
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#include <shellapi.h>
#elif __APPLE__
#include <unistd.h>
#else
#include <unistd.h>
#endif

void openURL(const char* url) {
#ifdef _WIN32
    ShellExecuteA(NULL, "open", url, NULL, NULL, SW_SHOWNORMAL);
#elif __APPLE__
    char command[256];
    snprintf(command, sizeof(command), "open %s", url);
    system(command);
#else
    char command[256];
    snprintf(command, sizeof(command), "xdg-open %s", url);
    system(command);
#endif
}

int main() {
    printf("Select a destination:\
");
    printf("1. Google\
");
    printf("2. YouTube\
");
    printf("3. Wikipedia\
");
    printf("4. GitHub\
");

    char choice[2];
    printf("Enter your choice (1-4): ");
    fgets(choice, sizeof(choice), stdin);

    if (strcmp(choice, "1") == 0) {
        openURL("https://www.google.com");
    } else if (strcmp(choice, "2") == 0) {
        openURL("https://www.youtube.com");
    } else if (strcmp(choice, "3") == 0) {
        openURL("https://www.wikipedia.org");
    } else if (strcmp(choice, "4") == 0) {
        openURL("https://www.github.com");
    } else {
        printf("Invalid choice. Please try again.\
");
    }

    return 0;
}
