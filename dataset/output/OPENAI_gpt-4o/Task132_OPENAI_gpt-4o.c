#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_EVENTS 100

typedef struct {
    char event[256];
    char timestamp[20];
} SecurityEvent;

typedef struct {
    SecurityEvent events[MAX_EVENTS];
    int count;
} SecurityEventLogger;

void currentDateTime(char* buffer) {
    time_t now = time(NULL);
    struct tm* tstruct = localtime(&now);
    strftime(buffer, 20, "%Y-%m-%d %H:%M:%S", tstruct);
}

void logEvent(SecurityEventLogger* logger, const char* event) {
    if (logger->count >= MAX_EVENTS) {
        printf("Event log is full\n");
        return;
    }
    strcpy(logger->events[logger->count].event, event);
    currentDateTime(logger->events[logger->count].timestamp);
    logger->count++;
}

void showEvents(const SecurityEventLogger* logger) {
    for (int i = 0; i < logger->count; i++) {
        printf("%s - %s\n", logger->events[i].timestamp, logger->events[i].event);
    }
}

int main() {
    SecurityEventLogger logger = {.count = 0};
    logEvent(&logger, "User login");
    logEvent(&logger, "File accessed");
    sleep(1);
    logEvent(&logger, "User logout");
    showEvents(&logger);
    return 0;
}