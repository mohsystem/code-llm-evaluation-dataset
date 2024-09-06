
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_DATA 3
#define MAX_LENGTH 50

void encrypt(char *data) {
    for (int i = 0; data[i] != '\\0'; i++) {
        data[i] = data[i] + 1;
    }
}

void decrypt(char *data) {
    for (int i = 0; data[i] != '\\0'; i++) {
        data[i] = data[i] - 1;
    }
}

int main() {
    char keys[MAX_DATA][MAX_LENGTH] = {"credit_card", "ssn", "password"};
    char values[MAX_DATA][MAX_LENGTH] = {"1234-5678-9012-3456", "123-45-6789", "mySecretPass123"};
    char encrypted[MAX_DATA][MAX_LENGTH];

    printf("Encrypted data:\\n");
    for (int i = 0; i < MAX_DATA; i++) {
        strcpy(encrypted[i], values[i]);
        encrypt(encrypted[i]);
        printf("%s: %s\\n", keys[i], encrypted[i]);
    }

    printf("\\nDecrypted data:\\n");
    for (int i = 0; i < MAX_DATA; i++) {
        decrypt(encrypted[i]);
        printf("%s: %s\\n", keys[i], encrypted[i]);
    }

    return 0;
}
