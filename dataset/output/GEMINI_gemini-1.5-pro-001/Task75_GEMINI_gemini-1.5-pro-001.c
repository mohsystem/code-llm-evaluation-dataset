#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <PID>\n", argv[0]);
        return 1;
    }

    int pid = atoi(argv[1]);

    if (kill(pid, SIGKILL) == 0) {
        printf("Process with PID %d has been terminated.\n", pid);
    } else {
        perror("Error terminating process");
        return 1;
    }

    return 0;
}