#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <PID>
", argv[0]);
        return 1;
    }
    pid_t pid = atoi(argv[1]);
    if (kill(pid, SIGTERM) == -1) {
        perror("kill");
        return 1;
    }
    return 0;
}