
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 256

void logEvent(const char* eventType, const char* description) {
    FILE* logFile = fopen("security_events.log", "a");
    if (logFile != NULL) {
        time_t now = time(NULL);
        char* dt = ctime(&now);
        dt[strlen(dt) - 1] = \'\\0\';  // Remove newline
        fprintf(logFile, "%s - Event Type: %s, Description: %s\
", dt, eventType, description);
        fclose(logFile);
    } else {
        fprintf(stderr, "Unable to open log file!\
");
    }
}

void monitorEvents() {
    char eventType[MAX_LENGTH], description[MAX_LENGTH];
    while (1) {
        printf("Enter event type (or \'q\' to quit): ");
        fgets(eventType, sizeof(eventType), stdin);
        eventType[strcspn(eventType, "\
")] = 0;  // Remove newline
        if (strcmp(eventType, "q") == 0 || strcmp(eventType, "Q") == 0) {
            break;
        }
        printf("Enter event description: ");
        fgets(description, sizeof(description), stdin);
        description[strcspn(description, "\
")] = 0;  // Remove newline
        logEvent(eventType, description);
    }
}

int main() {
    printf("Security Event Monitoring System\
");
    monitorEvents();
    return 0;
}
