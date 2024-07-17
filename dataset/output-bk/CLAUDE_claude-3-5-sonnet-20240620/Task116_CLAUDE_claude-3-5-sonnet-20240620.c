
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

int main() {
    char username[100];
    char password[100];
    
    printf("Enter username to change password: ");
    scanf("%s", username);
    
    printf("Enter new password: ");
    scanf("%s", password);

    // Perform privileged operation
    char command[256];
    snprintf(command, sizeof(command), "sudo passwd %s", username);
    int result = system(command);
    if (result == 0) {
        printf("Password changed successfully\
");
    } else {
        fprintf(stderr, "Failed to change password\
");
        return 1;
    }

    // Drop privileges
    uid_t uid = getuid();
    struct passwd *pw = getpwuid(uid);
    if (pw == NULL) {
        fprintf(stderr, "Failed to get user information\
");
        return 1;
    }

    if (setuid(pw->pw_uid) != 0) {
        fprintf(stderr, "Failed to drop privileges\
");
        return 1;
    }

    printf("Privileges dropped\
");
    return 0;
}
