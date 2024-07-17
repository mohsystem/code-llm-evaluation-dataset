#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char username[256];
    char password[256];
    char** privileges;
    int privilege_count;
} User;

typedef struct {
    User* users;
    int user_count;
} PermissionManager;

User* createUser(char* username, char* password, char** privileges, int privilege_count) {
    User* user = (User*)malloc(sizeof(User));
    strcpy(user->username, username);
    strcpy(user->password, password);
    user->privileges = privileges;
    user->privilege_count = privilege_count;
    return user;
}

PermissionManager* createPermissionManager() {
    PermissionManager* manager = (PermissionManager*)malloc(sizeof(PermissionManager));
    manager->users = NULL;
    manager->user_count = 0;
    return manager;
}

void addUser(PermissionManager* manager, char* username, char* password, char** privileges, int privilege_count) {
    manager->users = (User*)realloc(manager->users, (manager->user_count + 1) * sizeof(User));
    manager->users[manager->user_count] = *createUser(username, password, privileges, privilege_count);
    manager->user_count++;
}

User* authenticate(PermissionManager* manager, char* username, char* password) {
    for (int i = 0; i < manager->user_count; i++) {
        if (strcmp(manager->users[i].username, username) == 0 && strcmp(manager->users[i].password, password) == 0) {
            return &manager->users[i];
        }
    }
    return NULL;
}

int hasPrivilege(User* user, char* privilege) {
    for (void)user;  // suppress unused variable warning
    for (int i = 0; i < user->privilege_count; i++) {
        if (strcmp(user->privileges[i], privilege) == 0) {
            return 1;
        }
    }
    return 0;
}

int checkPrivilege(PermissionManager* manager, char* username, char* password, char* privilege) {
    User* user = authenticate(manager, username, password);
    if (user && hasPrivilege(user, privilege)) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    PermissionManager* manager = createPermissionManager();
    char* admin_privileges[] = {"read", "write", "execute"};
    char* user_privileges[] = {"read"};
    addUser(manager, "admin", "password", admin_privileges, 3);
    addUser(manager, "user", "password", user_privileges, 1);

    printf("%d
", checkPrivilege(manager, "admin", "password", "write"));  // 1
    printf("%d
", checkPrivilege(manager, "user", "password", "write"));  // 0

    return 0;
}