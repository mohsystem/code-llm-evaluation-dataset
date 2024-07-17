#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <PID>
", argv[0]);
        return 1;
    }
    int pid = atoi(argv[1]);
    if (kill(pid, SIGTERM) == -1) {
        perror("Error terminating process");
        return 1;
    }
    printf("Process with PID %d terminated successfully.
", pid);
    return 0;
}