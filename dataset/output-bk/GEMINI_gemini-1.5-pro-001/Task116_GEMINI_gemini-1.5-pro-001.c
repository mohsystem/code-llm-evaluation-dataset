#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <shadow.h>
#include <errno.h>

void drop_privileges(uid_t user_uid, gid_t user_gid) {
    if (setgid(user_gid) != 0) {
        perror("setgid");
        exit(1);
    }
    if (setuid(user_uid) != 0) {
        perror("setuid");
        exit(1);
    }
}

int main() {
    if (geteuid() != 0) {
        fprintf(stderr, "This program requires root privileges. Please run with sudo.
");
        return 1;
    }

    char username[256];
    char password[256];

    printf("Enter the username: ");
    scanf("%s", username);

    printf("Enter the new password: ");
    scanf("%s", password);

    struct spwd *sp = getspnam(username);
    if (sp == NULL) {
        fprintf(stderr, "User '%s' not found.
", username);
        return 1;
    }

    char *encrypted_password = crypt(password, "$6$salt$");
    if (encrypted_password == NULL) {
        perror("crypt");
        return 1;
    }

    sp->sp_pwdp = encrypted_password;

    if (putspent(sp, SHADOW_WRITE) == -1) {
        perror("putspent");
        return 1;
    }

    printf("Password for user '%s' changed successfully.
", username);

    drop_privileges(sp->sp_uid, sp->sp_gid);

    printf("Running as user: %s
", getlogin());

    return 0;
}