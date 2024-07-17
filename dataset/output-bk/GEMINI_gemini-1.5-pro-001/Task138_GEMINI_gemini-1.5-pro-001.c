#include <stdio.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_PERMISSIONS 50
#define MAX_USERNAME_LENGTH 50
#define MAX_PERMISSION_NAME_LENGTH 50

typedef struct {
    char name[MAX_PERMISSION_NAME_LENGTH];
} Permission;

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    Permission* permissions[MAX_PERMISSIONS];
    int permission_count;
} User;

User users[MAX_USERS];
int user_count = 0;

Permission permissions[MAX_PERMISSIONS];
int permission_count = 0;

Permission* create_permission(const char* name) {
    strcpy(permissions[permission_count].name, name);
    return &permissions[permission_count++];
}

User* create_user(const char* username) {
    strcpy(users[user_count].username, username);
    users[user_count].permission_count = 0;
    return &users[user_count++];
}

void add_permission_to_user(User* user, Permission* permission) {
    user->permissions[user->permission_count++] = permission;
}

int has_permission(User* user, const char* permission_name) {
    for (int i = 0; i < user->permission_count; i++) {
        if (strcmp(user->permissions[i]->name, permission_name) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    Permission* readPermission = create_permission("read");
    Permission* writePermission = create_permission("write");

    User* user1 = create_user("john_doe");
    add_permission_to_user(user1, readPermission);

    User* user2 = create_user("jane_doe");
    add_permission_to_user(user2, readPermission);
    add_permission_to_user(user2, writePermission);

    printf("%s has read permission: %s
", user1->username, has_permission(user1, "read") ? "true" : "false");
    printf("%s has write permission: %s
", user1->username, has_permission(user1, "write") ? "true" : "false");

    printf("%s has read permission: %s
", user2->username, has_permission(user2, "read") ? "true" : "false");
    printf("%s has write permission: %s
", user2->username, has_permission(user2, "write") ? "true" : "false");

    return 0;
}