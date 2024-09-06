
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>

#define MAX_USERNAME_LENGTH 32
#define MAX_PASSWORD_LENGTH 64

void drop_privileges(const char* username) {
    struct passwd* pw = getpwnam(username);
    if (pw == NULL) {
        fprintf(stderr, "Failed to get user info for %s\\n", username);
        exit(1);
    }

    if (setgid(pw->pw_gid) != 0) {
        fprintf(stderr, "Failed to set GID: %s\\n", strerror(errno));
        exit(1);
    }

    if (setuid(pw->pw_uid) != 0) {
        fprintf(stderr, "Failed to set UID: %s\\n", strerror(errno));
        exit(1);
    }

    printf("Privileges dropped to %s\\n", username);
}

void change_password(const char* username, const char* password) {
    char command[256];
    snprintf(command, sizeof(command), "echo '%s\\n%s' | passwd %s", password, password, username);
    int result = system(command);
    if (result == 0) {
        printf("Password changed successfully for %s\\n", username);
    } else {
        fprintf(stderr, "Failed to change password for %s\\n", username);
    }
}

int main() {
    if (geteuid() != 0) {
        fprintf(stderr, "This program must be run as root.\\n");
        return 1;
    }

    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter username to change password: ");
    if (fgets(username, sizeof(username), stdin) == NULL) {
        fprintf(stderr, "Error reading username\\n");
        return 1;
    }
    username[strcspn(username, "\\n")] = 0; // Remove newline

    printf("Enter new password: ");
    if (fgets(password, sizeof(password), stdin) == NULL) {
        fprintf(stderr, "Error reading password\\n");
        return 1;
    }
    password[strcspn(password, "\\n")] = 0; // Remove newline

    change_password(username, password);

    printf("Dropping privileges...\\n");
    drop_privileges("nobody");

    printf("Program continues with reduced privileges...\\n");

    return 0;
}
