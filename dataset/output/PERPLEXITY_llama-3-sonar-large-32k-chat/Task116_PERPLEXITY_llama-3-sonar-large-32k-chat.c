#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

void drop_privileges(uid_t uid, gid_t gid) {
    setgid(gid);
    setuid(uid);
}

int main() {
    char username[256];
    char password[256];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter new password: ");
    scanf("%s", password);
    char command[512];
    sprintf(command, "echo '%s' | sudo -S passwd %s", password, username);
    system(command);
    struct passwd *pw = getpwnam("nobody");  // replace with desired username
    drop_privileges(pw->pw_uid, pw->pw_gid);
    return 0;
}