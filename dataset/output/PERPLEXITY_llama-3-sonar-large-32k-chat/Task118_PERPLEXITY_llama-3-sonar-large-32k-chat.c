#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int validateIP(char *ip) {
    char *token = strtok(ip, ".");
    int count = 0;
    while (token != NULL) {
        count++;
        int num = atoi(token);
        if (num > 255 || num < 0) {
            return 0;
        }
        token = strtok(NULL, ".");
    }
    if (count != 4) {
        return 0;
    }
    return 1;
}

int main() {
    char ip[16];
    printf("Enter an IP address: ");
    scanf("%15s", ip);
    if (validateIP(ip)) {
        printf("IP address is valid\n");
    } else {
        printf("IP address is not valid\n");
    }
    return 0;
}