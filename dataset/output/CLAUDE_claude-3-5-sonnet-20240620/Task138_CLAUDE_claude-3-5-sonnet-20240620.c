
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_USERS 100
#define MAX_PERMISSIONS 10
#define MAX_USERNAME 50
#define MAX_ROLE 20

typedef struct {
    char username[MAX_USERNAME];
    char role[MAX_ROLE];
    char permissions[MAX_PERMISSIONS][MAX_ROLE];
    int permission_count;
} User;

typedef struct {
    User users[MAX_USERS];
    int user_count;
} PermissionManager;

void init_permission_manager(PermissionManager* pm) {
    pm->user_count = 0;
}

void add_user(PermissionManager* pm, const char* username, const char* role) {
    if (pm->user_count >= MAX_USERS) {
        printf("Cannot add more users.\
");
        return;
    }

    User* user = &pm->users[pm->user_count++];
    strncpy(user->username, username, MAX_USERNAME - 1);
    strncpy(user->role, role, MAX_ROLE - 1);

    user->permission_count = 0;
    if (strcmp(role, "admin") == 0) {
        strcpy(user->permissions[user->permission_count++], "read");
        strcpy(user->permissions[user->permission_count++], "write");
        strcpy(user->permissions[user->permission_count++], "delete");
        strcpy(user->permissions[user->permission_count++], "manage_users");
    } else if (strcmp(role, "editor") == 0) {
        strcpy(user->permissions[user->permission_count++], "read");
        strcpy(user->permissions[user->permission_count++], "write");
    } else if (strcmp(role, "viewer") == 0) {
        strcpy(user->permissions[user->permission_count++], "read");
    }
}

void remove_user(PermissionManager* pm, const char* username) {
    for (int i = 0; i < pm->user_count; i++) {
        if (strcmp(pm->users[i].username, username) == 0) {
            for (int j = i; j < pm->user_count - 1; j++) {
                pm->users[j] = pm->users[j + 1];
            }
            pm->user_count--;
            return;
        }
    }
}

void change_user_role(PermissionManager* pm, const char* username, const char* new_role) {
    for (int i = 0; i < pm->user_count; i++) {
        if (strcmp(pm->users[i].username, username) == 0) {
            User* user = &pm->users[i];
            strncpy(user->role, new_role, MAX_ROLE - 1);
            
            user->permission_count = 0;
            if (strcmp(new_role, "admin") == 0) {
                strcpy(user->permissions[user->permission_count++], "read");
                strcpy(user->permissions[user->permission_count++], "write");
                strcpy(user->permissions[user->permission_count++], "delete");
                strcpy(user->permissions[user->permission_count++], "manage_users");
            } else if (strcmp(new_role, "editor") == 0) {
                strcpy(user->permissions[user->permission_count++], "read");
                strcpy(user->permissions[user->permission_count++], "write");
            } else if (strcmp(new_role, "viewer") == 0) {
                strcpy(user->permissions[user->permission_count++], "read");
            }
            return;
        }
    }
}

bool check_permission(PermissionManager* pm, const char* username, const char* permission) {
    for (int i = 0; i < pm->user_count; i++) {
        if (strcmp(pm->users[i].username, username) == 0) {
            for (int j = 0; j < pm->users[i].permission_count; j++) {
                if (strcmp(pm->users[i].permissions[j], permission) == 0) {
                    return true;
                }
            }
            return false;
        }
    }
    return false;
}

void save_to_file(PermissionManager* pm, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\
");
        return;
    }

    for (int i = 0; i < pm->user_count; i++) {
        fprintf(file, "%s,%s", pm->users[i].username, pm->users[i].role);
        for (int j = 0; j < pm->users[i].permission_count; j++) {
            fprintf(file, ",%s", pm->users[i].permissions[j]);
        }
        fprintf(file, "\
");
    }

    fclose(file);
}

void load_from_file(PermissionManager* pm, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file for reading.\
");
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        char* username = strtok(line, ",");
        char* role = strtok(NULL, ",");
        if (username && role) {
            add_user(pm, username, role);
        }
    }

    fclose(file);
}

int main() {
    PermissionManager pm;
    init_permission_manager(&pm);

    add_user(&pm, "alice", "admin");
    add_user(&pm, "bob", "editor");
    add_user(&', type='text')