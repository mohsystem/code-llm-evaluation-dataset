// C
#include <stdio.h>
#include <string.h>

void encrypt(char *message, int key) {
    int len = strlen(message);
    for (int i = 0; i < len; i++) {
        message[i] += key;
    }
}

int main() {
    char message[100];
    int key;
    printf("Enter the message: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "
")] = 0;
    printf("Enter the secret key: ");
    scanf("%d", &key);
    encrypt(message, key);
    printf("Encrypted message: %s
", message);
    return 0;
}