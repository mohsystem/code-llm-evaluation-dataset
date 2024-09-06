// C

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PERMISSIONS 10

typedef struct {
    char name[50];
    char permissions[MAX_PERMISSIONS][50];
    int num_permissions;
} User;

bool has_permission(User* user, const char* permission) {
    for (int i = 0; i < user->num_permissions; i++) {
        if (strcmp(user->permissions[i], permission) == 0) {
            return true;
        }
    }
    return false;
}

// Example usage
int main() {
    User user = {"John", {"read", "write"}, 2};
    printf("%d\n", has_permission(&user, "read"));  // 1 (true)
    printf("%d\n", has_permission(&user, "execute"));  // 0 (false)
    return 0;
}