#include <stdio.h>
#include <time.h>
#include <unistd.h>

int main() {
    FILE *logFile = fopen("security.log", "a");

    while (1) {
        time_t now = time(0);
        char* dt = ctime(&now);
        fprintf(logFile, "Security event detected at %s", dt);
        fflush(logFile);
        sleep(5);
    }

    fclose(logFile);
    return 0;
}