#include <stdio.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_PERMISSIONS 50
#define MAX_USERNAME_LENGTH 50
#define MAX_PERMISSION_LENGTH 50

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char permissions[MAX_PERMISSIONS][MAX_PERMISSION_LENGTH];
    int permission_count;
} User;

User users[MAX_USERS];
int user_count = 0;

int find_user(const char *username) {
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, username) == 0) {
            return i;
        }
    }
    return -1;
}

void add_user(const char *username) {
    if (user_count < MAX_USERS) {
        strcpy(users[user_count].username, username);
        users[user_count].permission_count = 0;
        user_count++;
        printf("User created successfully.\n");
    } else {
        printf("Maximum number of users reached.\n");
    }
}

void add_permission(const char *username, const char *permission) {
    int user_index = find_user(username);
    if (user_index != -1) {
        if (users[user_index].permission_count < MAX_PERMISSIONS) {
            strcpy(users[user_index].permissions[users[user_index].permission_count], permission);
            users[user_index].permission_count++;
            printf("Permission added successfully.\n");
        } else {
            printf("Maximum number of permissions reached for this user.\n");
        }
    } else {
        printf("User not found.\n");
    }
}

void remove_permission(const char *username, const char *permission) {
    int user_index = find_user(username);
    if (user_index != -1) {
        for (int i = 0; i < users[user_index].permission_count; i++) {
            if (strcmp(users[user_index].permissions[i], permission) == 0) {
                // Shift remaining permissions
                for (int j = i; j < users[user_index].permission_count - 1; j++) {
                    strcpy(users[user_index].permissions[j], users[user_index].permissions[j + 1]);
                }
                users[user_index].permission_count--;
                printf("Permission removed successfully.\n");
                return;
            }
        }
        printf("Permission not found for this user.\n");
    } else {
        printf("User not found.\n");
    }
}

int has_permission(const char *username, const char *permission) {
    int user_index = find_user(username);
    if (user_index != -1) {
        for (int i = 0; i < users[user_index].permission_count; i++) {
            if (strcmp(users[user_index].permissions[i], permission) == 0) {
                return 1;
            }
        }
    }
    return 0;
}

void list_users() {
    if (user_count == 0) {
        printf("No users found.\n");
    } else {
        for (int i = 0; i < user_count; i++) {
            printf("%s\n", users[i].username);
        }
    }
}

int main() {
    char action[50], username[MAX_USERNAME_LENGTH], permission[MAX_PERMISSION_LENGTH];

    while (1) {
        printf("Enter action (create user, add permission, remove permission, check permission, list users, exit): ");
        fgets(action, sizeof(action), stdin);
        action[strcspn(action, "\n")] = 0; // Remove trailing newline

        if (strcmp(action, "create user") == 0) {
            printf("Enter username: ");
            fgets(username, sizeof(username), stdin);
            username[strcspn(username, "\n")] = 0;
            add_user(username);
        } else if (strcmp(action, "add permission") == 0) {
            printf("Enter username: ");
            fgets(username, sizeof(username), stdin);
            username[strcspn(username, "\n")] = 0;
            printf("Enter permission to add: ");
            fgets(permission, sizeof(permission), stdin);
            permission[strcspn(permission, "\n")] = 0;
            add_permission(username, permission);
        } else if (strcmp(action, "remove permission") == 0) {
            printf("Enter username: ");
            fgets(username, sizeof(username), stdin);
            username[strcspn(username, "\n")] = 0;
            printf("Enter permission to remove: ");
            fgets(permission, sizeof(permission), stdin);
            permission[strcspn(permission, "\n")] = 0;
            remove_permission(username, permission);
        } else if (strcmp(action, "check permission") == 0) {
            printf("Enter username: ");
            fgets(username, sizeof(username), stdin);
            username[strcspn(username, "\n")] = 0;
            printf("Enter permission to check: ");
            fgets(permission, sizeof(permission), stdin);
            permission[strcspn(permission, "\n")] = 0;
            if (has_permission(username, permission)) {
                printf("User has permission.\n");
            } else {
                printf("User does not have permission.\n");
            }
        } else if (strcmp(action, "list users") == 0) {
            list_users();
        } else if (strcmp(action, "exit") == 0) {
            break;
        } else {
            printf("Invalid action.\n");
        }
    }

    return 0;
}