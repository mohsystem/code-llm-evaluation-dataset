code here:
// C does not have a built-in way to open a web browser, so we'll use the system() function
#include <stdio.h>
#include <string.h>

void openWebpage(const char* url) {
    char command[256];
    sprintf(command, "start %s", url); // for Windows
    // sprintf(command, "open %s", url); // for macOS
    // sprintf(command, "xdg-open %s", url); // for Linux
    system(command);
}

int main() {
    printf("Enter 'google' to go to Google, 'facebook' to go to Facebook, or 'youtube' to go to YouTube: ");
    char user_input[256];
    fgets(user_input, 256, stdin);
    user_input[strcspn(user_input, "\n")] = 0; // remove newline character
    if (strcmp(user_input, "google") == 0) {
        openWebpage("https://www.google.com");
    } else if (strcmp(user_input, "facebook") == 0) {
        openWebpage("https://www.facebook.com");
    } else if (strcmp(user_input, "youtube") == 0) {
        openWebpage("https://www.youtube.com");
    } else {
        printf("Invalid input. Please try again.\n");
    }
    return 0;
}