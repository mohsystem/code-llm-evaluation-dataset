// C
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PERMISSIONS 10

typedef struct {
    char name[50];
    char permissions[MAX_PERMISSIONS][50];
    int numPermissions;
} User;

bool hasPermission(User user, const char *permission) {
    for (int i = 0; i < user.numPermissions; i++) {
        if (strcmp(user.permissions[i], permission) == 0) {
            return true;
        }
    }
    return false;
}

// Example usage
int main() {
    User user = {"John", {"read", "write"}, 2};
    printf("%d
", hasPermission(user, "read"));  // 1 (true)
    printf("%d
", hasPermission(user, "execute"));  // 0 (false)
    return 0;
}