
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>
#include <string.h>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <PID>\\n", argv[0]);
        return 1;
    }

    char* endptr;
    long pid = strtol(argv[1], &endptr, 10);

    if (*endptr != '\\0' || pid <= 0) {
        fprintf(stderr, "Invalid PID. Please provide a valid positive integer.\\n");
        return 1;
    }

    if (kill((pid_t)pid, SIGKILL) == 0) {
        printf("Process with PID %ld has been terminated.\\n", pid);
    } else {
        fprintf(stderr, "Failed to terminate process with PID %ld: %s\\n", pid, strerror(errno));
        return 1;
    }

    return 0;
}
