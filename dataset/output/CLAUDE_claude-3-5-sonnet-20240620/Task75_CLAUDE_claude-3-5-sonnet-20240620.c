
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <PID>\
", argv[0]);
        return 1;
    }

    int pid = atoi(argv[1]);
    if (pid <= 0) {
        printf("Invalid PID. Please provide a valid positive integer.\
");
        return 1;
    }

    if (kill(pid, SIGTERM) == 0) {
        printf("Process with PID %d terminated successfully.\
", pid);
    } else {
        perror("Failed to terminate process");
        return 1;
    }

    return 0;
}
