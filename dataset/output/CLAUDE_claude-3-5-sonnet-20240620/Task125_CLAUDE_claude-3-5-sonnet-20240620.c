
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_ROLES 4
#define MAX_RESOURCES 4
#define MAX_LENGTH 20

const char* roles[MAX_ROLES] = {"admin", "developer", "tester", "user"};
const char* resources[MAX_ROLES][MAX_RESOURCES] = {
    {"server", "database", "network", ""},
    {"database", "codebase", "", ""},
    {"codebase", "testbed", "", ""},
    {"application", "", "", ""}
};

int checkAccess(const char* userRole, const char* resource) {
    int roleIndex = -1;
    for (int i = 0; i < MAX_ROLES; i++) {
        if (strcmp(roles[i], userRole) == 0) {
            roleIndex = i;
            break;
        }
    }
    
    if (roleIndex != -1) {
        for (int i = 0; i < MAX_RESOURCES; i++) {
            if (strcmp(resources[roleIndex][i], resource) == 0) {
                return 1;
            }
        }
    }
    
    return 0;
}

void toLowerCase(char* str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int main() {
    char userRole[MAX_LENGTH];
    char resource[MAX_LENGTH];
    
    printf("Enter your role: ");
    scanf("%s", userRole);
    
    printf("Enter the resource you want to access: ");
    scanf("%s", resource);
    
    toLowerCase(userRole);
    toLowerCase(resource);
    
    if (checkAccess(userRole, resource)) {
        printf("Access granted to %s\
", resource);
    } else {
        printf("Access denied\
");
    }
    
    return 0;
}
