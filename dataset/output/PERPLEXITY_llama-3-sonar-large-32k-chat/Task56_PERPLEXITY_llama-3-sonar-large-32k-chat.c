#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char token[37];
    srand(time(NULL));
    for(int i = 0; i < 32; i++) {
        token[i] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789"[rand() % 62];
    }
    token[32] = '\0';
    printf("Token: %s
", token);
    return 0;
}