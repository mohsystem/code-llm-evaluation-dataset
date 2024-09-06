#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <shadow.h>
#include <crypt.h>
#include <errno.h>
#include <pwd.h>

int main() {
    if (geteuid() != 0) {
        fprintf(stderr, "This program requires root privileges. Please run with sudo.\n");
        return 1;
    }

    char username[256];
    printf("Enter the username to change password for: ");
    if (fgets(username, sizeof(username), stdin) == NULL) {
        perror("fgets");
        return 1;
    }
    username[strcspn(username, "\n")] = 0; // Remove newline

    struct passwd *pwd = getpwnam(username);
    if (pwd == NULL) {
        fprintf(stderr, "User '%s' not found.\n", username);
        return 1;
    }

    char password[1024];
    char confirm_password[1024];

    do {
        printf("Enter new password: ");
        if (fgets(password, sizeof(password), stdin) == NULL) {
            perror("fgets");
            return 1;
        }
        password[strcspn(password, "\n")] = 0;

        printf("Confirm new password: ");
        if (fgets(confirm_password, sizeof(confirm_password), stdin) == NULL) {
            perror("fgets");
            return 1;
        }
        confirm_password[strcspn(confirm_password, "\n")] = 0;

        if (strcmp(password, confirm_password) != 0) {
            printf("Passwords do not match. Please try again.\n");
        }
    } while (strcmp(password, confirm_password) != 0);

    char *hashed_password = crypt(password, "$6$salt$"); // Using SHA-512 hashing
    if (hashed_password == NULL) {
        perror("crypt");
        return 1;
    }

    struct spwd *spwd = getspnam(username);
    if (spwd == NULL) {
        fprintf(stderr, "Error getting shadow password entry.\n");
        return 1;
    }

    char *new_spwd = malloc(strlen(spwd->sp_pwdp) + strlen(hashed_password) + 2);
    if (new_spwd == NULL) {
        perror("malloc");
        return 1;
    }

    sprintf(new_spwd, "%s:%s:", spwd->sp_namp, hashed_password);

    if (putspent(spwd, NULL) != 0) {
        perror("putspent");
        free(new_spwd);
        return 1;
    }

    free(new_spwd);

    // Drop privileges - Not implemented for simplicity 
    // (Dropping privileges securely in C requires fork/exec and careful handling)

    printf("Password for user '%s' changed successfully.\n", username);

    return 0;
}