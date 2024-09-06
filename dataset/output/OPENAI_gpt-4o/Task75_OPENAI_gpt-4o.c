#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <PID>\n", argv[0]);
        return 1;
    }
    int pid = atoi(argv[1]);
    if (kill(pid, SIGKILL) == 0) {
        printf("Process %d terminated.\n", pid);
    } else {
        perror("Error");
    }
    return 0;
}