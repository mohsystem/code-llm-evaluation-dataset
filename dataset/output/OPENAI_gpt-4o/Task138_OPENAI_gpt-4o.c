#include <stdio.h>
#include <string.h>

#define MAX_PERMISSIONS 10

typedef struct {
    char username[50];
    char permissions[MAX_PERMISSIONS][50];
    int permission_count;
} User;

void add_permission(User* user, const char* permission) {
    if (user->permission_count < MAX_PERMISSIONS) {
        strcpy(user->permissions[user->permission_count++], permission);
    }
}

int has_permission(User* user, const char* permission) {
    for (int i = 0; i < user->permission_count; ++i) {
        if (strcmp(user->permissions[i], permission) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    User admin = {"admin", {}, 0};
    add_permission(&admin, "read");
    add_permission(&admin, "write");
    printf("Admin has 'read' permission: %s\n", has_permission(&admin, "read") ? "true" : "false");
    printf("Admin has 'delete' permission: %s\n", has_permission(&admin, "delete") ? "true" : "false");
    return 0;
}