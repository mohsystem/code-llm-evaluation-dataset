#include <stdio.h>
#include <time.h>

typedef struct {
    char eventType[50];
    char description[100];
    time_t timestamp;
} SecurityEvent;

void logEvent(SecurityEvent event) {
    printf("%s - %s: %s
", ctime(&event.timestamp), event.eventType, event.description);
}

typedef struct {
    SecurityEvent* eventLog;
    int eventCount;
} SecurityMonitor;

void logEventToMonitor(SecurityMonitor* monitor, SecurityEvent event) {
    monitor->eventLog[monitor->eventCount] = event;
    logEvent(event);
    monitor->eventCount++;
}

void monitorEvents(SecurityMonitor* monitor) {
    for (int i = 0; i < monitor->eventCount; i++) {
        printf("Monitoring: %s - %s
", monitor->eventLog[i].eventType, monitor->eventLog[i].description);
    }
}

int main() {
    SecurityMonitor monitor;
    monitor.eventLog = (SecurityEvent*)malloc(2 * sizeof(SecurityEvent));
    monitor.eventCount = 0;

    SecurityEvent event1 = {"Login Attempt", "User attempted to login", time(0)};
    logEventToMonitor(&monitor, event1);

    SecurityEvent event2 = {"File Access", "User accessed confidential file", time(0)};
    logEventToMonitor(&monitor, event2);

    monitorEvents(&monitor);
    return 0;
}