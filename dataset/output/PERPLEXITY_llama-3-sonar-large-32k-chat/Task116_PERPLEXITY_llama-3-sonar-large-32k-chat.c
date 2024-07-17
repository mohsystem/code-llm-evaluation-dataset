#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/prctl.h>

int main(int argc, char *argv[]) {
    // Perform privileged operation
    setuid(0);
    system("passwd " + argv[1]);

    // Drop privileges
    setuid(getuid());

    // Verify privileges dropped
    system("whoami");

    return 0;
}