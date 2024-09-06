#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    if (geteuid() != 0) {
        fprintf(stderr, "This script must be run as root!\n");
        return 1;
    }
    
    char username[256];
    printf("Enter username to change password: ");
    scanf("%s", username);

    char command[512];
    snprintf(command, sizeof(command), "echo \"%s:newpassword\" | chpasswd", username);
    system(command);

    // Drop privileges
    if (setuid(geteuid()) != 0) {
        fprintf(stderr, "Failed to drop privileges\n");
        return 1;
    }
    printf("Privileges have been dropped.\n");
    return 0;
}