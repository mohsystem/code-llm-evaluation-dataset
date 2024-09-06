#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void generateToken() {
    char token[16];
    for (int i = 0; i < 16; ++i) {
        token[i] = rand() % 256;
    }

    printf("C Generated Token: ");
    for (int i = 0; i < 16; ++i) {
        printf("%02x", (unsigned char)token[i]);
    }
    printf("\n");
}

int main() {
    sleep(5); // Waiting for 5 seconds
    srand(time(0));
    generateToken();
    return 0;
}