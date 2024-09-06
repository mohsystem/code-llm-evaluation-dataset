#include <stdio.h>
#include <string.h>

typedef struct {
    char username[256];
    char password[256];
    char privileges[256][256];
    int privilege_count;
} User;

typedef struct {
    User users[256];
    int user_count;
} PermissionManager;

void addUser(PermissionManager *manager, char *username, char *password, char *privileges[]) {
    strcpy(manager->users[manager->user_count].username, username);
    strcpy(manager->users[manager->user_count].password, password);
    for (int i = 0; privileges[i] != NULL; i++) {
        strcpy(manager->users[manager->user_count].privileges[i], privileges[i]);
    }
    manager->users[manager->user_count].privilege_count = i;
    manager->user_count++;
}

User authenticate(PermissionManager *manager, char *username, char *password) {
    for (int i = 0; i < manager->user_count; i++) {
        if (strcmp(manager->users[i].username, username) == 0 && strcmp(manager->users[i].password, password) == 0) {
            return manager->users[i];
        }
    }
    User user;
    strcpy(user.username, "");
    strcpy(user.password, "");
    return user;
}

bool checkPrivilege(User user, char *privilege) {
    for (int i = 0; i < user.privilege_count; i++) {
        if (strcmp(user.privileges[i], privilege) == 0) {
            return true;
        }
    }
    return false;
}

int main() {
    PermissionManager manager;
    manager.user_count = 0;

    addUser(&manager, "admin", "password", (char *[]) {"read", "write", "execute", NULL});
    addUser(&manager, "user", "password", (char *[]) {"read", NULL});

    User admin = authenticate(&manager, "admin", "password");
    User user = authenticate(&manager, "user", "password");

    printf("%d\n", checkPrivilege(admin, "write"));  // 1
    printf("%d\n", checkPrivilege(user, "write"));  // 0

    return 0;
}