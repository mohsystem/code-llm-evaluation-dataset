#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: terminate_process <PID>\n");
        return 1;
    }

    int pid = atoi(argv[1]);
    if (kill(pid, SIGKILL) == -1) {
        printf("Error: unable to terminate process\n");
        return 1;
    }

    return 0;
}