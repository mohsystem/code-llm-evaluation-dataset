// C
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <PID>
", argv[0]);
        return 1;
    }

    int pid = atoi(argv[1]);

    if (pid <= 0) {
        printf("Invalid PID.
");
        return 1;
    }

    if (pid == getpid()) {
        printf("Cannot terminate the current process.
");
        return 1;
    }

    if (kill(pid, SIGTERM) == -1) {
        perror("Error terminating process");
        return 1;
    }

    printf("Process %d terminated.
", pid);
    return 0;
}