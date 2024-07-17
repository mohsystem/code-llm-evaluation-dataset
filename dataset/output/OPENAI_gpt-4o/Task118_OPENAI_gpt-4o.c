#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool isValidNumber(char *num) {
    int len = strlen(num);
    if(len > 3) return false;
    for(int i = 0; i < len; i++) {
        if ((num[i] < '0' || num[i] > '9')) return false;
    }
    if (atoi(num) > 255 || (num[0] == '0' && len > 1)) return false;
    return true;
}

bool isValidIPAddress(char *ip) {
    int numCount = 0;
    char *token = strtok(ip, ".");
    while(token) {
        if (!isValidNumber(token)) return false;
        token = strtok(NULL, ".");
        numCount++;
    }
    return numCount == 4;
}

int main() {
    char ip1[] = "192.168.0.1";
    char ip2[] = "256.256.256.256";
    printf("%d
", isValidIPAddress(ip1)); // true - 1
    printf("%d
", isValidIPAddress(ip2)); // false - 0
    return 0;
}