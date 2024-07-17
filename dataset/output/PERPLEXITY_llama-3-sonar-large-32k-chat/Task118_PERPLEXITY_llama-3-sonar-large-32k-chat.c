#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int validateIP(char *ip) {
    char *token = strtok(ip, ".");
    int i, num;
    for (i = 0; i < 4; i++) {
        if (token == NULL) return 0;
        num = atoi(token);
        if (num < 0 || num > 255) return 0;
        token = strtok(NULL, ".");
    }
    if (token != NULL) return 0;
    return 1;
}

int main() {
    char ip[16];
    printf("Enter an IP address: ");
    fgets(ip, 16, stdin);
    ip[strcspn(ip, "
")] = 0; // remove newline character
    if (validateIP(ip)) {
        printf("IP address is valid
");
    } else {
        printf("IP address is not valid
");
    }
    return 0;
}