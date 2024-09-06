#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void logEvent(const char* event) {
    FILE* logFile = fopen("security_log.txt", "a");
    if (logFile != NULL) {
        time_t now = time(NULL);
        fprintf(logFile, "%s - %s\n", ctime(&now), event);
        fclose(logFile);
    } else {
        fprintf(stderr, "Error writing to log file.\n");
    }
}

void monitorEvents() {
    char event[256];
    while (true) {
        printf("Enter an event (or 'quit' to exit): ");
        fgets(event, 256, stdin);
        event[strcspn(event, "\n")] = 0; // remove newline character
        if (strcmp(event, "quit") == 0) {
            break;
        }
        logEvent(event);
    }
}

int main() {
    monitorEvents();
    return 0;
}