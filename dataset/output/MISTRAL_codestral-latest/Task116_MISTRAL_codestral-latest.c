// C
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("Running as root
");
    uid_t uid = getuid();
    gid_t gid = getgid();

    // Perform privileged operations here

    // Drop privileges
    setgid(gid);
    setuid(uid);
    printf("Dropped privileges
");
    return 0;
}