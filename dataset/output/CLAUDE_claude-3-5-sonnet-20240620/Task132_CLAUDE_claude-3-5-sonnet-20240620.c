
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 256

void logEvent(const char* eventType, const char* description) {
    FILE* logFile = fopen("security_events.log", "a");
    if (logFile != NULL) {
        time_t now;
        time(&now);
        char* time_str = ctime(&now);
        time_str[strlen(time_str) - 1] = '\\0';  // Remove newline
        fprintf(logFile, "%s - INFO - Event Type: %s, Description: %s\\n", 
                time_str, eventType, description);
        fclose(logFile);
    } else {
        fprintf(stderr, "Unable to open log file!\\n");
    }
}

int main() {
    char eventType[MAX_LENGTH];
    char description[MAX_LENGTH];

    printf("Security Event Monitoring System\\n");

    while (1) {
        printf("Enter event type (or 'q' to quit): ");
        fgets(eventType, sizeof(eventType), stdin);
        eventType[strcspn(eventType, "\\n")] = 0;  // Remove newline

        if (strcmp(eventType, "q") == 0 || strcmp(eventType, "Q") == 0) {
            break;
        }

        printf("Enter event description: ");
        fgets(description, sizeof(description), stdin);
        description[strcspn(description, "\\n")] = 0;  // Remove newline

        logEvent(eventType, description);
        printf("Event logged successfully.\\n");
    }

    printf("Monitoring ended. Check 'security_events.log' for recorded events.\\n");
    return 0;
}
