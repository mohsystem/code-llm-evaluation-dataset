#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

void log_event(const char *event_type, const char *message) {
    FILE *log_file = fopen("security_events.log", "a");
    if (log_file == NULL) {
        perror("Error opening log file");
        return;
    }

    time_t now = time(NULL);
    struct tm *timeinfo = localtime(&now);
    char timestamp[20];
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", timeinfo);

    fprintf(log_file, "%s - %s - %s\n", timestamp, event_type, message);
    fclose(log_file);
}

void monitor_file_changes(const char *file_path) {
    struct stat file_stat;
    if (stat(file_path, &file_stat) == -1) {
        log_event("Error", "Failed to get file status");
        return;
    }

    time_t last_modified_time = file_stat.st_mtime;

    while (1) {
        sleep(5); // Check every 5 seconds

        if (stat(file_path, &file_stat) == -1) {
            log_event("Error", "Failed to get file status");
            continue;
        }

        if (file_stat.st_mtime != last_modified_time) {
            log_event("File Change Detected", file_path);
            last_modified_time = file_stat.st_mtime;
        }
    }
}

int main() {
    const char *file_to_monitor = "/path/to/your/important_file.txt"; // Replace with actual path
    monitor_file_changes(file_to_monitor);
    return 0;
}