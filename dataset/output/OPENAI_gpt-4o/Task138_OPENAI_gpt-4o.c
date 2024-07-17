#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char username[50];
    char *permissions[10];
    int permission_count;
} User;

User* createUser(const char *username) {
    User *user = (User*) malloc(sizeof(User));
    strcpy(user->username, username);
    user->permission_count = 0;
    return user;
}

void addPermission(User *user, const char *permission) {
    user->permissions[user->permission_count] = (char*) malloc(strlen(permission) + 1);
    strcpy(user->permissions[user->permission_count], permission);
    user->permission_count++;
}

int hasPermission(User *user, const char *permission) {
    for(int i = 0; i < user->permission_count; i++) {
        if(strcmp(user->permissions[i], permission) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    User *user = createUser("john_doe");
    addPermission(user, "read");
    addPermission(user, "write");

    printf("User %s has read permission: %d
", user->username, hasPermission(user, "read"));
    printf("User %s has write permission: %d
", user->username, hasPermission(user, "write"));
    printf("User %s has delete permission: %d
", user->username, hasPermission(user, "delete"));

    for(int i = 0; i < user->permission_count; i++) {
        free(user->permissions[i]);
    }
    free(user);

    return 0;
}