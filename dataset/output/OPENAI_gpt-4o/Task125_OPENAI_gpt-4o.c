#include <stdio.h>
#include <string.h>

const char* accessResource(const char* user) {
    if (strcmp(user, "admin") == 0) {
        return "Access to administrative resources granted.";
    } else if (strcmp(user, "user") == 0) {
        return "Access to user resources granted.";
    } else if (strcmp(user, "guest") == 0) {
        return "Access to guest resources granted.";
    } else {
        return "No resources available for this user role";
    }
}

int main() {
    char userRole[10];
    printf("Enter user role (admin/user/guest): ");
    scanf("%s", userRole);

    const char* result = accessResource(userRole);
    printf("%s\n", result);

    return 0;
}