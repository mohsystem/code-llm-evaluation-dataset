#include <stdio.h>
#include <time.h>
#include <unistd.h>

int main() {
    FILE *logFile = fopen("security.log", "a");

    if (logFile == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    while (1) {
        // Simulate a security event
        time_t now = time(0);
        char* timeStr = ctime(&now);
        fprintf(logFile, "Security event detected at %s\n", timeStr);
        fflush(logFile);
        sleep(1);
    }

    fclose(logFile);
    return 0;
}