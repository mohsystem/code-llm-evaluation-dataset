#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <pid>
", argv[0]);
        return 1;
    }
    
    pid_t pid = (pid_t)atoi(argv[1]);
    if (kill(pid, SIGKILL) == 0) {
        printf("Process %d terminated.
", pid);
    } else {
        perror("Failed to terminate process");
        return 1;
    }
    
    return 0;
}