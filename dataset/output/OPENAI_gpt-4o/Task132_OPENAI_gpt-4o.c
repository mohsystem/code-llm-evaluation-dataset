#include <stdio.h>
#include <time.h>

void logEvent(const char *event) {
    FILE *logfile = fopen("security.log", "a");
    if (logfile == NULL) {
        return;
    }

    time_t now = time(NULL);
    struct tm *local = localtime(&now);
    fprintf(logfile, "%04d/%02d/%02d %02d:%02d:%02d - %s
",
            local->tm_year + 1900, local->tm_mon + 1, local->tm_mday,
            local->tm_hour, local->tm_min, local->tm_sec, event);
    fclose(logfile);
}

int main() {
    logEvent("User login detected.");
    logEvent("Unauthorized access attempt detected.");
    logEvent("File integrity check failed.");
    return 0;
}